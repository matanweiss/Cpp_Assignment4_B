#ifndef TEAM
#define TEAM
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

class Team {
  Character *leader;
  vector<Character *> members;

public:
  Team(const Team& other);
  Team(Character *leader);
  Team(Team&& other)noexcept;
  Team& operator=(const Team& other);
  Team& operator=( Team&& other)noexcept;
  void add(Character *member);
  void attack(Team *other);
  int stillAlive();
  void print();
  Character* findAliveMember(Team* team);
  Character *getLeader() const;
  vector<Character *> *getMembers();
  void setLeader(Character*);
  void setMembers(vector<Character*>*);
  virtual ~Team();
};

namespace ariel {};
#endif