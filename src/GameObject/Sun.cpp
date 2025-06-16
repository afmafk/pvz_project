#include "pvz/GameObject/Sun.hpp"

Sun::Sun(int x, int y, std::shared_ptr<GameWorld> gameWorld,int endTime,int xSpeed,int ySpeed,int acceleration) :
	GameObject(ImageID::SUN, x, y, LayerID::SUN, 80, 80, AnimID::IDLE), time(0), endTime(endTime), gameWorld(gameWorld), xSpeed(xSpeed), ySpeed(ySpeed), acceleration(acceleration) {}


void Sun::Update() {
	if (isActive) {
		MoveTo(GetX() + xSpeed, GetY() + ySpeed);
		ySpeed += acceleration;
	}
	time++;
	if (isActive && time >= endTime) {
		isActive = false;
		time = 0;
	}
	else if (time == 300) {
		SetIsDead(true);
	}

}

void Sun::OnClick() {
	SetIsDead(true);
	gameWorld->SetCursorCost(-25);
	gameWorld->SetSun();
}