#ifndef SHOVEL__HPP__
#define SHOVEL__HPP__

#include "GameObject.hpp"
#include "../utils.hpp"
#include "../GameWorld/GameWorld.hpp"

class GameWorld;

class Shovel : public GameObject {
	std::shared_ptr<GameWorld> gameWorld = nullptr;
public:
	Shovel(std::shared_ptr<GameWorld> gameWorld);
	void OnClick() override;
};





#endif