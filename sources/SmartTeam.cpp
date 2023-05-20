#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>

SmartTeam::SmartTeam(const SmartTeam &other)
    : Team(other), leader(other.leader) {}

SmartTeam::SmartTeam(Character *leader) : Team(leader), leader(leader) {
  team.push_back(leader);
}

SmartTeam::SmartTeam(SmartTeam &&other) noexcept : Team(other) {
  leader = other.leader;
  team = other.team;
}

SmartTeam &SmartTeam::operator=(const SmartTeam &other) {
  leader = other.leader;
  team = other.team;
  return *this;
}

SmartTeam &SmartTeam::operator=(SmartTeam &&other) noexcept {
  leader = other.leader;
  team = other.team;
  return *this;
}

void SmartTeam::add(Character *member) {
  if (team.size() == 10)
    return;
  team.push_back(member);
}

void SmartTeam::attack(Team *other) {}

int SmartTeam::stillAlive() { return 0; }

void SmartTeam::print() {}

SmartTeam::~SmartTeam() {}