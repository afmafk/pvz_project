#include "pvz/GameObject/BucketHeadZombie.hpp"

BucketHeadZombie::BucketHeadZombie(int x, int y, std::shared_ptr<GameWorld> gameWorld) :Zombie(x, y, gameWorld){
	ChangeImage(ImageID::BUCKET_HEAD_ZOMBIE);
	SetHP(1300);
}

void BucketHeadZombie::Update() {
	RegularUpdate();
	if (isBucketHead && GetHP() <= 200) {
		isBucketHead = false;
		ChangeImage(ImageID::REGULAR_ZOMBIE);
	}
}
