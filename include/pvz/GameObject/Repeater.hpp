#ifndef REPEATER_HPP__
#define REPEATER_HPP__

#include "Plant.hpp"

class GameWorld;
class Repeater : public Plant {
	int time = 0;
	bool IsShootFirst = false;
public:
	Repeater(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	static std::shared_ptr<GameObject> Create(int x, int  y, std::shared_ptr<GameWorld> gameWorld);
	void Repeater::CreateCooldownMask()override;
	void Update() override;
};

#endif 