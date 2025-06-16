#include "pvz/GameObject/GameObject.hpp"


GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
	ObjectBase(imageID, x, y, layer, width, height, animID){}
void GameObject::Update() {}
void GameObject::OnClick(){}

bool GameObject::GetIsDead() const{
	return isDead;
}
void GameObject::SetIsDead(bool state) {
	isDead = state;
}
bool GameObject::GetIsZombie() const {
	return isZombie;
}
void GameObject::SetIsZombie() {
	isZombie ^= 1;
}
bool GameObject::GetIsPlant() const {
	return isPlant;
}
void GameObject::SetIsPlant() {
	isPlant ^= 1;
}
int GameObject::Attack(std::shared_ptr<GameObject> other) {
	return 0;
}
void GameObject::Attacked(int damege) {}