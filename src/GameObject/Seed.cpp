#include "pvz/GameObject/Seed.hpp"


Seed::Seed(ImageID imageID, int x, int y, std::shared_ptr<GameWorld> gameWorld, CursorID cursorID, int cost) :
	GameObject(imageID, x, y, LayerID::UI, 50, 70, AnimID::NO_ANIMATION), gameWorld(gameWorld), cursorID(cursorID), cost(cost) {
}

void Seed::OnClick() {
	if(gameWorld->GetCursor() == cursorID) {
		gameWorld->SetCursor(CursorID::NONE, 0);
		return;
	}
	else if(gameWorld->GetSun()>=cost)
		gameWorld->SetCursor(cursorID, cost);
}