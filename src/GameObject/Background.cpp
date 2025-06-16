#include "pvz/GameObject/Background.hpp"

Background::Background()
    : GameObject(ImageID::BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LayerID::BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, AnimID::NO_ANIMATION) {}