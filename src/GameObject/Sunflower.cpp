#include "pvz/GameObject/Sunflower.hpp"

class GameWorld;
Sunflower::Sunflower(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	Plant(ImageID::SUNFLOWER, x, y, gameWorld, 300), sunTime(randInt(0, 240)) {CreateCooldownMask();}

std::shared_ptr<GameObject> Sunflower::Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	return std::make_shared<Sunflower>(x, y, gameWorld);
}

void Sunflower::CreateCooldownMask() {
	gameWorld->CreateCooldownMask(130, WINDOW_HEIGHT - 44, 240);
}

void Sunflower::Update() {
	if (GetHP() <= 0) {
		SetIsDead(true);
	}
	else {
		sunTime++;
		if (sunTime >= 300) {
			gameWorld->CreateSun(GetX(), GetY(), 12, -1, 4, -1);
			sunTime = 0;
		}
	}
}