#include "pvz/GameObject/Pea.hpp"

Pea::Pea(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	GameObject(ImageID::PEA, x, y, LayerID::PROJECTILES, 28, 28, AnimID::NO_ANIMATION), gameWorld(gameWorld) {
}


void Pea::Update() {
	if (GetX() >= WINDOW_WIDTH)
		SetIsDead(true);
	else 
		MoveTo(GetX() + 8, GetY());
}

int Pea::Attack(std::shared_ptr<GameObject> other) {
	if (!other->GetIsZombie()||this->GetIsDead()) return 0;
	SetIsDead(true);
	return 20;
}