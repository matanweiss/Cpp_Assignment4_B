#include "Team.hpp"
#include "Character.hpp"
#include <cfloat>
#include <vector>

Team::Team(const Team &other) : leader(other.leader) {}

Team::Team(Character *leader) : leader(leader) { members.push_back(leader); }

Team::Team(Team &&other) noexcept {
  leader = other.leader;
  members = other.members;
}

Team &Team::operator=(const Team &other) {
  leader = other.leader;
  members = other.members;
  return *this;
}

Team &Team::operator=(Team &&other) noexcept {
  leader = other.leader;
  members = other.members;
  return *this;
}

void Team::add(Character *member) {
  if (members.size() == 10)
    return;
  members.push_back(member);
}

void Team::attack(Team *other) {
  leader = findAliveMember(this);
  Character *target = findAliveMember(other);
  for (Character *member : members) {
    if (member->getIsNinja())
      continue;
    if (!target->isAlive())
      target = findAliveMember(other);
    member->attack(target);
  }
  for (Character *member : members) {
    if (!member->getIsNinja())
      continue;
    if (!target->isAlive())
      target = findAliveMember(other);
    member->attack(target);
  }
}

int Team::stillAlive() {
  int result = 0;
  for (Character *member : members)
    if (member->isAlive())
      result++;
  return result;
}

void Team::print() {
  for (Character *member : members)
    if (!member->getIsNinja() && member->isAlive())
      cout << member->print() << endl;
  for (Character *member : members)
    if (member->getIsNinja() && member->isAlive())
      cout << member->print() << endl;
}

Character *Team::findAliveMember(Team *team) {
  if (team->leader->isAlive())
    return team->leader;

  double shortest = DBL_MAX;
  Character *result = NULL;
  for (Character *member : team->members)
    if (member->isAlive() && team->leader->distance(*member) < shortest) {
      shortest = team->leader->distance(*member);
      result = member;
    }
  return result;
}

Team::~Team() {}