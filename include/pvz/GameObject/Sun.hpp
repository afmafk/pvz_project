#ifndef SUN__HPP__
#define SUN__HPP__

#include "GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class Sun : public GameObject {
	std::shared_ptr<GameWorld> gameWorld = nullptr;
	bool isActive = true;
	int time;
	int endTime;
	int xSpeed;
	int ySpeed;
	int acceleration;

public:
	Sun(int x, int y, std::shared_ptr<GameWorld> gameWorld, int endTime, int xSpeed, int ySpeed, int acceleration);
	void Update() override;
	void OnClick() override;

};

#endif