#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

class CooldownMask : public GameObject , public std::enable_shared_from_this<CooldownMask>{
	std::shared_ptr<GameWorld> gameWorld = nullptr;
	int beginTime = 0;
	int wholeTime = 0;
public:
	CooldownMask(int x, int y, std::shared_ptr<GameWorld> gameWorld, int wholeTime);
	void Update() override;
    
};

#endif 