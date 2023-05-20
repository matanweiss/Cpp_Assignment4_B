#include "Cowboy.hpp"
#include "Character.hpp"
#include <stdexcept>

Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 110, 0), ammo(6) {}
void Cowboy::shoot(Character *enemy) {
  if (!isAlive())
    throw runtime_error("Cowboy is not alive");
  if (!enemy->isAlive())
    throw runtime_error("Enemy is not alive");
  if (this == enemy)
    throw runtime_error("Cannot attack itself");
  if (hasboolets()) {
    enemy->hit(10);
    ammo -= 1;
  }
}
bool Cowboy::hasboolets() { return 0 < ammo; }
void Cowboy::reload() {
  if (!isAlive())
    throw runtime_error("Cowboy is not alive");
  ammo = 6;
}
string Cowboy::print() {
  if (isAlive())
    return "name: C" + getName() + ", health: " + to_string(getHealth()) +
           ", location: " + getLocation().print();
  return "name: (C" + getName() + "), location: " + getLocation().print();
}

void Cowboy::attack(Character *enemy) {
  if (!isAlive() || !enemy->isAlive())
    return;
  if (hasboolets())
    shoot(enemy);
  else
    reload();
}
