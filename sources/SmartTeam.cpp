#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>

SmartTeam::SmartTeam(const Team &other) : Team(other) {}

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

SmartTeam::SmartTeam(Team &&other) noexcept : Team(other) {}

SmartTeam &SmartTeam::operator=(Team &other) {
  setLeader(other.getLeader());
  setMembers(other.getMembers());
  return *this;
}

SmartTeam &SmartTeam::operator=(Team &&other) noexcept {
  setLeader(other.getLeader());
  setMembers(other.getMembers());
  return *this;
}

void SmartTeam::attack(Team *other) {
  if (!other)
    throw invalid_argument("Team cannot be null");
  if (!other->stillAlive())
    return;
  setLeader(findAliveMember(this));
  for (Character *member : *getMembers()) {
    Character *target = NULL;

    // member is ninja, do the most damage within 1 meters
    if (member->getIsNinja()) {
      int damage = 0;
      for (Character *enemy : *other->getMembers()) {
        if (enemy->isAlive()) {
          if (member->distance(enemy) < 1 && damage < enemy->getHealth()) {
            damage = enemy->getHealth();
            target = enemy;
          }
        }
      }

      // if there are no close enemies, find enemy to move closer to
      if (target == NULL)
        target = findAliveMember(other);
    }

    // member is cowboy, if the enemy has 10 or less hp then attack it
    else {
      for (Character *enemy : *other->getMembers()) {
        if (enemy->isAlive() && enemy->getHealth() <= 10) {
          target = enemy;
        }
      }
    }
    member->attack(target);
  }
}

void SmartTeam::print() {
  for (Character *member : *getMembers())
    if (member->isAlive())
      cout << member->print() << endl;
}

SmartTeam::~SmartTeam() {}