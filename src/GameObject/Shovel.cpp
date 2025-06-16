#include "pvz/GameObject/Shovel.hpp"


Shovel::Shovel(std::shared_ptr<GameWorld> gameWorld) :
	GameObject(ImageID::SHOVEL, 600, WINDOW_HEIGHT - 40, LayerID::UI, 50, 50, AnimID::NO_ANIMATION), gameWorld(gameWorld) {
}

void Shovel::OnClick() {
	if (gameWorld->GetCursor() == CursorID::SHOVEL) {
		gameWorld->SetCursor(CursorID::NONE, 0);
	}
	else if (gameWorld->GetCursor() == CursorID::NONE) {
		gameWorld->SetCursor(CursorID::SHOVEL, 0);
	}
}