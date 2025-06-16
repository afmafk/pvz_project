#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/Background.hpp"
#include "pvz/GameObject/Sunflower.hpp"
#include "pvz/GameObject/Peashooter.hpp"
#include "pvz/GameObject/Repeater.hpp"
#include "pvz/GameObject/Wallnut.hpp"
#include "pvz/GameObject/CherryBomb.hpp"
#include "pvz/GameObject/PlantingSpot.hpp"
#include "pvz/GameObject/Seed.hpp"
#include "pvz/GameObject/Shovel.hpp"
#include "pvz/GameObject/CooldownMask.hpp"
#include "pvz/GameObject/Sun.hpp"
#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameObject/BucketHeadZombie.hpp"
#include "pvz/GameObject/Pea.hpp"
#include "pvz/GameObject/Explosion.hpp"

#include<unordered_map>
#include<functional>


void GameWorld::Init() {
	
	gameObjectsList.push_back(std::make_shared<Background>());
	displaySun = std::make_unique<TextBase>(60, WINDOW_HEIGHT - 80, std::to_string(sun));
	displayWave = std::make_unique<TextBase>(WINDOW_WIDTH - 160, 8, "Wave: "+std::to_string(wave));

	for (int col = 0; col < GAME_COLS; ++col)
		for (int row = 0; row < GAME_ROWS; ++row)
			gameObjectsList.push_back(std::make_shared<PlantingSpot>(FIRST_COL_CENTER+LAWN_GRID_WIDTH * col, FIRST_ROW_CENTER+LAWN_GRID_HEIGHT * row,shared_from_this()));
	
	gameObjectsList.push_back(std::make_shared<Seed>(ImageID::SEED_SUNFLOWER, 130, WINDOW_HEIGHT - 44, shared_from_this(), CursorID::SUNFLOWER, 50));
	gameObjectsList.push_back(std::make_shared<Seed>(ImageID::SEED_PEASHOOTER, 190, WINDOW_HEIGHT -44, shared_from_this(), CursorID::PEASHOOTER, 100));
	gameObjectsList.push_back(std::make_shared<Seed>(ImageID::SEED_WALLNUT, 250, WINDOW_HEIGHT - 44, shared_from_this(), CursorID::WALLNUT, 50));
	gameObjectsList.push_back(std::make_shared<Seed>(ImageID::SEED_CHERRY_BOMB, 310, WINDOW_HEIGHT - 44, shared_from_this(), CursorID::CHERRY_BOMB, 150));
	gameObjectsList.push_back(std::make_shared<Seed>(ImageID::SEED_REPEATER, 370, WINDOW_HEIGHT - 44, shared_from_this(), CursorID::REPEATER, 200));

	gameObjectsList.push_back(std::make_shared<Shovel>(shared_from_this()));
}


LevelStatus GameWorld::Update() {
	tick++;
	lastWaveTick++;
	//Create sun
	if ((tick-180)%300 == 0) {
		CreateSun(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT-1, randInt(63, 263), 0, -2, 0);
	}
	//Create new wave of zombies
	if ((wave == 0 && lastWaveTick >= 1200) || (wave <= 22 && lastWaveTick >= 600 - 20 * wave) || (wave >= 23 && lastWaveTick >= 150)) {
		wave++, lastWaveTick = 0;
		displayWave->SetText("Wave: " + std::to_string(wave));
		int zombieNumber = (15 + wave) / 10;
		for (int i = 1; i <= zombieNumber; ++i) {
			CreateZombie(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), randInt(1, GAME_ROWS) * LAWN_GRID_HEIGHT);
		}
		
	}
	
	//Update objects
	for (auto it = gameObjectsList.begin(); it != gameObjectsList.end(); ++it) {
		auto current = it;
		(*current)->Update();
	}
	//Check collision and attack
	for (auto it1 = gameObjectsList.begin(); it1 != gameObjectsList.end(); ++it1) {
		auto it2 = it1;
		++it2;
		for (; it2 != gameObjectsList.end(); ++it2) {
			if (CollisionCheck(*it1, *it2)) {
				(*it1)->Attacked((*it2) -> Attack(*it1));
				(*it2)->Attacked((*it1) -> Attack(*it2));
			}
		}
	}
	//Erase dead objects and check game status
	for (auto it = gameObjectsList.begin(); it != gameObjectsList.end(); ) {
		auto current = it++;
		if (current == gameObjectsList.end())
			break;
		if ((*current)->GetX() < 0) {
			displayWave->SetColor(1, 1, 1);
			displayWave->SetText(std::to_string(wave));
			displayWave->MoveTo(330, 50);
			return LevelStatus::LOSING;
		}
		if ((*current)->GetIsDead()) {
			gameObjectsList.erase(current);
		}
	}
	displaySun->SetText(std::to_string(sun));
	return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
	while(!gameObjectsList.empty()) {
		gameObjectsList.pop_back();
	}
	displaySun = nullptr;
	displayWave=nullptr;
	cursor = CursorID::NONE;
	cursorCost = 0;
	sun = 50;
	wave = 0;
	lastWaveTick = 0;
	tick = 0;
}

void GameWorld::CreatePlant(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	std::unordered_map<CursorID, std::function<std::shared_ptr<GameObject>(int x, int y, std::shared_ptr<GameWorld> gameWorld)>> functionMap = {
	{CursorID::SUNFLOWER, Sunflower::Create},
	{CursorID::PEASHOOTER, Peashooter::Create},
	{CursorID::REPEATER, Repeater::Create},
	{CursorID::WALLNUT, Wallnut::Create},
	{CursorID::CHERRY_BOMB, CherryBomb::Create}
	};
	gameObjectsList.push_back(functionMap[cursor](x, y,gameWorld));
	cursor = CursorID::NONE; 
}

void GameWorld::CreateCooldownMask(int x, int y, int wholeTime) {
	gameObjectsList.push_back(std::make_shared<CooldownMask>(x, y, shared_from_this(),wholeTime));
}
void GameWorld::CreateSun(int x, int y, int endTime, int xSpeed, int ySpeed, int acceleration) {
	gameObjectsList.push_back(std::make_shared<Sun>(x, y, shared_from_this(), endTime, xSpeed, ySpeed, acceleration));
}

void GameWorld::CreatePea(int x, int y) {
	gameObjectsList.push_back(std::make_shared<Pea>(x, y, shared_from_this()));
}
void GameWorld::CreateExplosion(int x, int y) {
	gameObjectsList.push_back(std::make_shared<Explosion>(x, y, shared_from_this()));
}

void GameWorld::CreateZombie(int x, int y) {
	int p1 = 20, p2 = 2 * (wave >= 8 ? wave - 8 : 0);
	if(randInt(0, p1 + p2) < p1) {
		gameObjectsList.push_back(std::make_shared<Zombie>(x,y, shared_from_this()));
	}
	else gameObjectsList.push_back(std::make_shared<BucketHeadZombie>(x,y, shared_from_this()));
}

void GameWorld::SetCursor(CursorID cursorID, int cost) {
	cursor = cursorID;
	cursorCost = cost;
}

void GameWorld::SetCursorCost(int cursorCost) {
	this->cursorCost = cursorCost;
}

CursorID GameWorld::GetCursor() const{
	return cursor;
}

int GameWorld::GetSun()const {
	return sun;
}
void GameWorld::SetSun() {
	sun = sun-cursorCost;
	cursorCost = 0;
}

bool GameWorld::IsExistZombie(int x, int y) const{
	for(const auto& obj : gameObjectsList) {
		if (obj->GetIsZombie() && obj->GetX() >= x && obj->GetY() == y - FIRST_ROW_CENTER + LAWN_GRID_HEIGHT) {
			return true;
		}
	}
	return false;
}

bool GameWorld::CollisionCheck(std::shared_ptr<GameObject> left, std::shared_ptr<GameObject> right) {
	if (!(left->GetIsZombie() ^ right->GetIsZombie())) return false;
	int x1 = left -> GetX();
	int y1 = left -> GetY();
	int w1 = left -> GetWidth();
	int h1 = left -> GetHeight();
	int x2 = right -> GetX();
	int y2 = right -> GetY();
	int w2 = right -> GetWidth();
	int h2 = right -> GetHeight();

	bool overlapX = std::abs(x1 - x2) < (w1 + w2) / 2;
	bool overlapY = std::abs(y1 - y2) < (h1 + h2) / 2;
	return overlapX && overlapY;
}
