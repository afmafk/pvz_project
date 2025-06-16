#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "Plant.hpp"
class GameWorld;
class Peashooter : public Plant {
	int time = 0;
public:
	Peashooter(int width, int height, std::shared_ptr<GameWorld> gameWorld);
	static std::shared_ptr<GameObject> Create(int x, int  y, std::shared_ptr<GameWorld> gameWorld);
	void CreateCooldownMask() override;
	void Update() override;
};

#endif 