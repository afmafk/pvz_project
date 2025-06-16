#include "pvz/GameObject/Explosion.hpp"

Explosion::Explosion(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	GameObject(ImageID::EXPLOSION, x, y, LayerID::PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, AnimID::NO_ANIMATION),  gameWorld(gameWorld){
}


void Explosion::Update() {
	time++;
	if (time >= 3) {
		SetIsDead(true);
	}
}

int Explosion::Attack(std::shared_ptr<GameObject> other) {
	if (!other->GetIsZombie()) return 0;
	return 10000;
}
