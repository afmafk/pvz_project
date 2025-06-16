#ifndef ZOMBIE_HPP__  
#define ZOMBIE_HPP__  

#include "GameObject.hpp"  
#include "../GameWorld/GameWorld.hpp"  

class GameWorld;  
class Zombie : public GameObject {  
private:  
    int HP = 200;  
    bool isEat = false;
    bool lastIsEat = false;
    std::shared_ptr<GameWorld> gameWorld = nullptr; 
protected:
    int GetHP() const;  
    void SetHP(int HP);  
	void RegularUpdate();
public:
    void Update() override;
    Zombie(int x, int y, std::shared_ptr<GameWorld> gameWorld);  
    int Attack(std::shared_ptr<GameObject> other) override;
    void Attacked(int damage) override;
};  

#endif