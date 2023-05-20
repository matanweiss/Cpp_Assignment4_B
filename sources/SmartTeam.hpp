#pragma once
#include "Team.hpp"
#include <vector>

class SmartTeam : public Team {
  Character *leader;
  vector<Character *> team;

public:
  SmartTeam(const SmartTeam &other);
  SmartTeam(Character *leader);
  SmartTeam(SmartTeam &&other) noexcept;
  SmartTeam &operator=(const SmartTeam &other);
  SmartTeam &operator=(SmartTeam &&other) noexcept;
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~SmartTeam();
};

namespace ariel {};
