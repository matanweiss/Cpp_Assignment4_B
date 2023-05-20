#pragma once
#include "Team.hpp"
#include <vector>

class Team2:public Team {
  Character *leader;
  vector<Character *> team;

public:
  Team2(const Team2& other);
  Team2(Character *leader);
  Team2(Team2&& other)noexcept;
  Team2& operator=(const Team2& other);
  Team2& operator=( Team2&& other)noexcept;
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  ~Team2();
};

namespace ariel {};
