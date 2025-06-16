#ifndef PLANT_HPP__  
#define PLANT_HPP__  

#include "GameObject.hpp"  
#include "../GameWorld/GameWorld.hpp"  

class GameWorld;  
class Plant : public GameObject {  
private:  
    int HP;
protected:  
    std::shared_ptr<GameWorld> gameWorld = nullptr;  
    Plant(ImageID imageID, int x, int y, std::shared_ptr<GameWorld> gameWorld, int HP);  
    virtual ~Plant() = default;
    int GetHP() const;
    void SetHP(int HP);
    
public:  
    void OnClick() override; 
    virtual void CreateCooldownMask() = 0; 
    void Attacked(int damage) override;
};  

#endif