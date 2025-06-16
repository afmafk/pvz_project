#include "pvz/GameObject/Wallnut.hpp"

Wallnut::Wallnut(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	Plant(ImageID::WALLNUT, x, y, gameWorld,4000) {CreateCooldownMask();}

std::shared_ptr<GameObject> Wallnut::Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	return std::make_shared<Wallnut>(x, y, gameWorld);
}

void Wallnut::CreateCooldownMask() {
	gameWorld->CreateCooldownMask(250, WINDOW_HEIGHT - 44, 900);
}

void Wallnut::Update() {
	if (GetHP() <= 0) {
		SetIsDead(true);
	}
	else {
		if (GetHP() <= 1333) {
			ChangeImage(ImageID::WALLNUT_CRACKED);
		}
	}
}