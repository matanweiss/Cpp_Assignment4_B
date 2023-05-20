#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <string>

Character::Character(string name, const Point &location, int health,
                     bool isNinja)
    : name(name), location(location), health(health), isNinja(isNinja) {}

bool Character::isAlive() { return 0 < health; }
bool Character::getIsNinja() { return isNinja; }
double Character::distance(const Character &other) {
  return location.distance(other.getLocation());
}
void Character::hit(int damage) { health = max(0, health - damage); }
string Character::getName() { return name; }
Point Character::getLocation() const { return location; }
void Character::setLocation(Point newLocation) { location = newLocation; }
int Character::getHealth() { return health; }
