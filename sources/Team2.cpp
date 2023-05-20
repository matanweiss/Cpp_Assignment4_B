#include "Team2.hpp"
#include <vector>

Team2::Team2(const Team &other) : Team(other) {}

Team2::Team2(Character *leader) : Team(leader) {}

void Team2::attack(Team *other) {
  if (!other)
    throw invalid_argument("Team cannot be null");
  if (!other->stillAlive())
    return;
  setLeader(findAliveMember(this));
  Character *target = findAliveMember(other);
  for (Character *member : *getMembers()) {
    if (!target->isAlive()) {
      target = findAliveMember(other);
      if (!target)
        return;
    }
    member->attack(target);
  }
}

void Team2::print() {
  for (Character *member : *getMembers())
    cout << member->print() << endl;
}
