#include "pvz/GameObject/Plant.hpp"

Plant::Plant(ImageID imageID, int x, int y, std::shared_ptr<GameWorld> gameWorld,int HP) :
	GameObject(imageID, x, y, LayerID::PLANTS, 60, 80, AnimID::IDLE), gameWorld(gameWorld), HP(HP) {
	gameWorld->SetSun();
	SetIsPlant();
}
void Plant::OnClick() {
	if (gameWorld->GetCursor() == CursorID::SHOVEL) {
		gameWorld->SetCursor(CursorID::NONE, 0);
		SetIsDead(true);
		
	}
}
int Plant::GetHP() const{
	return HP;
}
void Plant::SetHP(int HP) {
	this->HP = HP;
}

void Plant::Attacked(int damage) {
	HP -= damage;
}
