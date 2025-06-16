#include "pvz/GameObject/Repeater.hpp"

Repeater::Repeater(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	Plant(ImageID::REPEATER, x,y,gameWorld,300) {CreateCooldownMask();}

std::shared_ptr<GameObject> Repeater::Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	return std::make_shared<Repeater>(x, y, gameWorld);
}

void Repeater::CreateCooldownMask() {
	gameWorld->CreateCooldownMask(370, WINDOW_HEIGHT - 44, 240);
}

void Repeater::Update() {
	if (GetHP() <= 0) {
		SetIsDead(true);
	}
	else {
		time++;
		if (time >= 30 && gameWorld->IsExistZombie(GetX(), GetY())) {
			gameWorld->CreatePea(GetX() + 30, GetY() + 20);
			time = 0;
			IsShootFirst = true;
		}
		if (time == 5 && IsShootFirst) {
			gameWorld->CreatePea(GetX() + 30, GetY() + 20);
			IsShootFirst = false;
		}
	}
}