#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include "pvz/Framework/ObjectBase.hpp"

class GameWorld;

class GameObject : public ObjectBase {  
	bool isDead = false;  
	bool isZombie = false;
	bool isPlant = false;
protected:  
	void SetIsZombie();
	void SetIsPlant();
	GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);  
	void OnClick() override;  
	virtual ~GameObject() = default; 
public:  
	void Update() override;  
	bool GetIsDead() const; 
	void SetIsDead(bool state);  
	bool GetIsZombie() const;
	bool GetIsPlant() const;
	virtual int Attack(std::shared_ptr<GameObject> other);
	virtual void Attacked(int damage);
	
};


#endif // !GAMEOBJECT_HPP__
