#ifndef BUCKETHEADZOMBIE_HPP__
#define BUCKETHEADZOMBIE_HPP__

#include "Zombie.hpp"


class BucketHeadZombie : public Zombie {
	bool isBucketHead = true; 
public:
	BucketHeadZombie(int x, int y, std::shared_ptr<GameWorld> gameWorld);
	void Update() override;
};

#endif 