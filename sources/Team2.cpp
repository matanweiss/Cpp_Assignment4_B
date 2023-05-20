#include "Team2.hpp"
#include <vector>

Team2::Team2(const Team &other) : Team(other), leader(other.getLeader()) {}

Team2::Team2(Character *leader) : Team(leader), leader(leader) {
  members.push_back(leader);
}

Team2::Team2(Team &&other) noexcept : Team(other) {
  leader = other.getLeader();
  members = *other.getMembers();
}

Team2 &Team2::operator=(Team &other) {
  leader = other.getLeader();
  members = *other.getMembers();
  return *this;
}

Team2 &Team2::operator=(Team &&other) noexcept {
  leader = other.getLeader();
  members = *other.getMembers();
  return *this;
}

void Team2::attack(Team *other) {
  if (!other)
    throw invalid_argument("Team cannot be null");
  if (!other->stillAlive())
    return;
  leader = findAliveMember(this);
  Character *target = findAliveMember(other);
  for (Character *member : members) {
    if (!target->isAlive())
      target = findAliveMember(other);
    member->attack(target);
  }
}

void Team2::print() {
  for (Character *member : members)
    if (member->isAlive())
      cout << member->print() << endl;
}

Team2::~Team2() {}