#pragma once
#include "Ninja.hpp"

class TrainedNinja : public Ninja {

public:
  TrainedNinja(string name, const Point &location)
      : Ninja(std::move(name), location, TRAINED_NINJA_HP, TRAINED_NINJA_SPEED) {}
};