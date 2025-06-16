#ifndef EXPLOSION__HPP__
#define EXPLOSION__HPP__

#include "GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Explosion : public GameObject {
	std::shared_ptr<GameWorld> gameWorld;
	bool isActive = true;
	int time = 0;

public:
	Explosion(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	void Update() override;
	int Attack(std::shared_ptr<GameObject> other) override;
};

#endif