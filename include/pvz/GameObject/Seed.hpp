#ifndef SEED__HPP__
#define SEED__HPP__

#include "GameObject.hpp"
#include "../utils.hpp"
#include "../GameWorld/GameWorld.hpp"

class GameWorld;

class Seed : public GameObject {
	std::shared_ptr<GameWorld> gameWorld = nullptr;
	CursorID cursorID;
	int cost;
public:
	Seed(ImageID imageID,int x, int y, std::shared_ptr<GameWorld> gameWorld,CursorID cursorID, int cost);
	void OnClick() override;
};





#endif