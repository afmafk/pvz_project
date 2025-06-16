#ifndef PEA_HPP__  
#define PEA_HPP__  

#include "GameObject.hpp"  
#include "../GameWorld/GameWorld.hpp"  

class GameWorld;  
class Pea : public GameObject {  
    std::shared_ptr<GameWorld> gameWorld = nullptr;  

public:  
    void Update() override;  
    Pea(int x, int y, std::shared_ptr<GameWorld> gameWorld);  
    int Attack(std::shared_ptr<GameObject> other) override;
};  

#endif