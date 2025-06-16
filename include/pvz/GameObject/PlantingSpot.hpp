#ifndef PLANTINGSPOT__HPP__
#define PLANTINGSPOT__HPP__

#include "GameObject.hpp"
#include "../GameWorld/GameWorld.hpp"

class GameWorld;

class PlantingSpot : public GameObject {
	std::shared_ptr<GameWorld> gameWorld = nullptr;
public:
	PlantingSpot(int x, int y,std::shared_ptr<GameWorld> gameWorld);
	void OnClick() override;
};





#endif