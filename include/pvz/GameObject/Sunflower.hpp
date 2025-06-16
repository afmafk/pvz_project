#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "Plant.hpp"
#include "pvz/GameWorld/GameWorld.hpp"


class Sunflower : public Plant {
	int sunTime;
public:
	Sunflower(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	static std::shared_ptr<GameObject> Create(int x, int y, std::shared_ptr<GameWorld> gameWorld) ;
	void CreateCooldownMask() override;
	void Update() override;
};

#endif 