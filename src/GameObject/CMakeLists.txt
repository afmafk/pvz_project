cmake_minimum_required(VERSION 3.16)

add_library(
  GameObject
  STATIC
  GameObject.cpp
  Background.cpp
  Plant.cpp
  Sunflower.cpp
  Repeater.cpp
  CherryBomb.cpp
  Wallnut.cpp
  Peashooter.cpp
  PlantingSpot.cpp
  Seed.cpp
  Shovel.cpp
  CooldownMask.cpp
  Sun.cpp
  Zombie.cpp
  Pea.cpp
  Explosion.cpp
  BucketHeadZombie.cpp
)

target_link_libraries(
  GameObject
  Framework
)
