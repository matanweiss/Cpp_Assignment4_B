#include "Team2.hpp"
#include "Character.hpp"
#include <vector>

Team2::Team2(const Team2 &other) :Team(other), leader(other.leader) {}

Team2::Team2(Character *leader) : Team(leader),leader(leader) { team.push_back(leader); }

Team2::Team2(Team2 &&other)noexcept:Team(other) {
  leader = other.leader;
  team = other.team;
}

Team2 &Team2::operator=(const Team2 &other) {
  leader = other.leader;
  team = other.team;
  return *this;
}

Team2 &Team2::operator=( Team2 &&other) noexcept{
  leader = other.leader;
  team = other.team;
  return *this;
}

void Team2::add(Character *member) {
  if (team.size() == 10)
    return;
  team.push_back(member);
}

void Team2::attack(Team *other) {}

int Team2::stillAlive() { return 0; }

void Team2::print() {}

Team2::~Team2() {}