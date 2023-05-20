#include "Ninja.hpp"
#include "Character.hpp"

Ninja::Ninja(string name, const Point &location, int health, int speed)
    : Character(name, location, health, 1), speed(speed) {}
void Ninja::move(const Character *enemy) {
  if (!isAlive())
    return;
  setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), speed));
}
void Ninja::slash(Character *enemy) {
  if (!isAlive())
    throw runtime_error("Ninja is not alive");
  if (!enemy->isAlive())
    throw runtime_error("Enemy is not alive");
  if (isAlive() && getLocation().distance(enemy->getLocation()) < 1)
    enemy->hit(40);
}
string Ninja::print() {
  if (isAlive())
    return "name: N" + getName() + ", health: " + to_string(getHealth()) +
           ", location: " + getLocation().print();
  return "name: (N" + getName() + "), location: " + getLocation().print();
}

void Ninja::attack(Character *enemy) {
  if (!isAlive() || !enemy->isAlive())
    return;
  if (this == enemy) // NOT WORKING
    throw runtime_error("Cannot attack itself");
  if (distance(enemy) < 1)
    slash(enemy);
  else
    move(enemy);
}