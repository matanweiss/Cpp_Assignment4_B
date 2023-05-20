#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <string>

Character::Character(string name, const Point &location, int health,
                     bool isNinja)
    : name(name), location(location), health(health), isNinja(isNinja),
      isInTeam(false) {}

Character::Character(const Character &other)
    : name(other.name), location(other.location), health(other.health),
      isNinja(other.isNinja), isInTeam(other.isInTeam) {}

Character::Character(Character &&other) noexcept
    : name(other.name), location(other.location), health(other.health),
      isInTeam(other.isInTeam), isNinja(other.isNinja) {}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;

  name = other.name;
  location = other.location;
  health = other.health;
  isInTeam = other.isInTeam;
  isNinja = other.isNinja;

  return *this;
}

Character &Character::operator=(Character &&other) noexcept {
  if (this == &other)
    return *this;

  name = other.name;
  location = other.location;
  health = other.health;
  isInTeam = other.isInTeam;
  isNinja = other.isNinja;

  return *this;
}
bool Character::isAlive() { return 0 < health; }
bool Character::getIsNinja() { return isNinja; }
bool Character::getIsInTeam() { return isInTeam; }
void Character::setIsInTeam() { isInTeam = true; }
double Character::distance(Character *other) {
  return location.distance(other->getLocation());
}
void Character::hit(int damage) {
  if (damage < 0)
    throw invalid_argument("damage can only be positive integer");
  health = max(0, health - damage);
}
string Character::getName() { return name; }
Point Character::getLocation() const { return location; }
void Character::setLocation(Point newLocation) { location = newLocation; }
int Character::getHealth() { return health; }
