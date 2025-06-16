#include "pvz/GameObject/Peashooter.hpp"

Peashooter::Peashooter(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	Plant(ImageID::PEASHOOTER, x, y ,gameWorld, 300) {CreateCooldownMask();}

std::shared_ptr<GameObject> Peashooter::Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	return std::make_shared<Peashooter>(x, y, gameWorld);
}

void Peashooter::CreateCooldownMask() {
	gameWorld->CreateCooldownMask(190, WINDOW_HEIGHT - 44, 240);
}

void Peashooter::Update() {
	if (GetHP() <= 0) {
		SetIsDead(true);
	}
	else {
		time++;
		if (time >= 30 && gameWorld->IsExistZombie(GetX(),GetY())) {
			gameWorld->CreatePea(GetX() + 30, GetY() + 20);
			time = 0;
		}
	}
}