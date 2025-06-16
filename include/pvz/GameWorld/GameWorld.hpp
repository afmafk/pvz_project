#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameObject/Background.hpp"

#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

class GameObject;
class GameWorld : public WorldBase,public std::enable_shared_from_this<GameWorld>  {
	std::list<std::shared_ptr<GameObject>> gameObjectsList;
	CursorID cursor = CursorID::NONE;
	int cursorCost = 0;
	int sun = 50;
	int wave = 0;
	int lastWaveTick = 0;
	int tick = 0;
	std::unique_ptr<TextBase>displaySun;
	std::unique_ptr<TextBase>displayWave;
	
public:
  GameWorld() = default;
  ~GameWorld() = default;
  void Init() override;
  LevelStatus Update() override;
  void CleanUp() override;
  void CreatePlant(int x,int y,std::shared_ptr<GameWorld>gameWorld);
  CursorID GetCursor() const;
  void SetCursor(CursorID cursorID,int cost);
  void CreateCooldownMask(int x, int y, int wholeTime);
  void CreateSun(int x, int y, int endTime, int xSpeed, int ySpeed, int acceleration);
  void CreatePea(int x, int y);
  void CreateExplosion(int x, int y);
  void CreateZombie(int x, int y);
  int GetSun()const;
  void SetSun();
  void SetCursorCost(int cursorCost);
  bool IsExistZombie(int x, int y)const;
  bool CollisionCheck(std::shared_ptr<GameObject> left,std::shared_ptr<GameObject> right);

};

#endif // !GAMEWORLD_HPP__

