#ifndef CHARACTER
#define CHARACTER
#include "Point.hpp"
using namespace std;

class Character {
  string name;
  int health;
  bool isNinja;
  Point location;
  bool isInTeam;

public:
  Character(string name, const Point &location, int health, bool isNinja);
  Character(const Character &other);
  Character(Character &&other) noexcept;
  Character &operator=(const Character &other);
  Character &operator=(Character &&other) noexcept;
  bool isAlive();
  bool getIsNinja();
  bool getIsInTeam();
  void setIsInTeam();
  double distance(Character *other);
  void hit(int damage);
  string getName();
  virtual string print() = 0;
  virtual void attack(Character *enemy) = 0;
  Point getLocation() const;
  void setLocation(Point newLocation);
  int getHealth();
  virtual ~Character(){};
};
#endif