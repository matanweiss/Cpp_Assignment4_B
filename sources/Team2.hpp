#ifndef TEAM2
#define TEAM2
#include "Team.hpp"

class Team2 : public Team {

public:
  Team2(const Team &other);
  Team2(Character *leader);
  void attack(Team *other);
  void print();
};
#endif