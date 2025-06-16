#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "Plant.hpp"

class GameWorld;
class Wallnut : public Plant {
public:
	Wallnut(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	static std::shared_ptr<GameObject> Create(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	void CreateCooldownMask() override;
	void Update() override;
};

#endif 