#pragma once
#include "Team.hpp"

class SmartTeam : public Team {

public:
  SmartTeam(const Team &other);
  SmartTeam(Character *leader);
  SmartTeam(Team &&other) noexcept;
  SmartTeam &operator=( Team &other);
  SmartTeam &operator=(Team &&other) noexcept;
  void attack(Team *other);
  void print();
  ~SmartTeam();
};