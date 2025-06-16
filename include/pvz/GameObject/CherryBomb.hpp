#ifndef CHEERRYBOMB_HPP__
#define CHEERRYBOMB_HPP__

#include "Plant.hpp"

class GameWorld;
class CherryBomb : public Plant {
	int time = 0;
public:
	CherryBomb(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	static std::shared_ptr<GameObject> Create(int x, int  y, std::shared_ptr<GameWorld> gameWorld);
	void CherryBomb::CreateCooldownMask()override;
	void Update() override;
};

#endif 