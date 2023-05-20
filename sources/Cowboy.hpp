#pragma once
#include "Character.hpp"

class Cowboy : public Character {
  int ammo;

public:
  Cowboy(string name,const Point &location);
  void shoot(Character* enemy);
  bool hasboolets();
  void reload();
  string print() override;
  void attack(Character * enemy) override;
};