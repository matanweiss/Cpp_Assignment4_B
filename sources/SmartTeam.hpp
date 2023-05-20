#ifndef SMARTTEAM
#define SMARTTEAM
#include "Team.hpp"

class SmartTeam : public Team {

public:
  SmartTeam(const Team &other);
  SmartTeam(Character *leader);
  void attack(Team *other);
  void print();
};
#endif