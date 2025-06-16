#include "pvz/GameObject/Zombie.hpp"

Zombie::Zombie(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	GameObject(ImageID::REGULAR_ZOMBIE, x, y, LayerID::ZOMBIES, 20, 50, AnimID::WALK), gameWorld(gameWorld) {
	SetIsZombie();
}

int Zombie::GetHP() const {
	return HP;
}
void Zombie::SetHP(int HP) {
	this->HP = HP;
}

void Zombie::RegularUpdate() {
	if (GetHP() <= 0&&!GetIsDead()) {
		SetIsDead(true);
	}
	else {
		if (isEat) {
			if(!lastIsEat)PlayAnimation(AnimID::EAT);
		}
		else {
			if (lastIsEat) PlayAnimation(AnimID::WALK);
			MoveTo(GetX() -1 , GetY());
		}
		lastIsEat = isEat;
		isEat = false;
	}
}
void Zombie::Update() {
	RegularUpdate();
}
int Zombie::Attack(std::shared_ptr<GameObject> other) {
	if (!other->GetIsPlant()) return 0;
	isEat = true;
	return 3;
}
void Zombie::Attacked(int damage) {
	HP -= damage;
}