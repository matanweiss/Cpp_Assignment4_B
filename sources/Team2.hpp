#pragma once
#include "Team.hpp"

class Team2 : public Team {
  Character *leader;
  vector<Character *> members;

public:
  Team2(const Team &other);
  Team2(Character *leader);
  Team2(Team &&other) noexcept;
  Team2 &operator=( Team &other);
  Team2 &operator=(Team &&other) noexcept;
  void attack(Team *other);
  void print();
  ~Team2();
};