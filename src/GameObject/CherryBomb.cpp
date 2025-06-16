#include "pvz/GameObject/CherryBomb.hpp"

CherryBomb::CherryBomb(int x, int y, std::shared_ptr<GameWorld> gameWorld) :
	Plant(ImageID::CHERRY_BOMB,x,y,gameWorld,4000) {CreateCooldownMask();}

std::shared_ptr<GameObject> CherryBomb::Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) {
	return std::make_shared<CherryBomb>(x, y,gameWorld);
}

void CherryBomb::CreateCooldownMask() {
	gameWorld->CreateCooldownMask(310, WINDOW_HEIGHT - 44, 1200);
}

void CherryBomb::Update() {
	time++;
	if (time == 15) {
		SetIsDead(true);
		gameWorld->CreateExplosion(GetX(), GetY());
	}
}