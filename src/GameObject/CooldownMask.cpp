#include "pvz/GameObject/CooldownMask.hpp"

CooldownMask::CooldownMask(int x, int y, std::shared_ptr<GameWorld> gameWorld,int wholeTime) :
	GameObject(ImageID::COOLDOWN_MASK, x, y, LayerID::COOLDOWN_MASK,50,70,AnimID::NO_ANIMATION),gameWorld(gameWorld),beginTime(0),wholeTime(wholeTime){}

void CooldownMask::Update() {
	beginTime++;
	if(beginTime >= wholeTime) {
		SetIsDead(true);
	}

}