#include "pvz/GameObject/PlantingSpot.hpp"


PlantingSpot::PlantingSpot(int x, int y,std::shared_ptr<GameWorld> gameWorld) :
	GameObject(ImageID::NONE, x, y, LayerID::UI, 60, 80, AnimID::NO_ANIMATION),gameWorld(gameWorld){ }

void PlantingSpot::OnClick() {
	if (gameWorld->GetCursor() == CursorID::NONE|| gameWorld->GetCursor() == CursorID::SHOVEL)
		return;
	gameWorld->CreatePlant(GetX(), GetY(), gameWorld->shared_from_this());
}