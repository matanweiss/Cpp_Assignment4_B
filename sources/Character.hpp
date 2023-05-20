#pragma once
#include "Point.hpp"
using namespace std;

class Character {
  string name;
  Point location;
  int health;
  bool isNinja;

public:
  Character(string name,  const Point &location, int health, bool isNinja);
  bool isAlive();
  bool getIsNinja();
  double distance(const Character &other);
  void hit(int damage);
  string getName();
  virtual string print() = 0;
  virtual void attack(Character* enemy) = 0;
  Point getLocation() const;
  void setLocation(Point newLocation);
  int getHealth();
};
