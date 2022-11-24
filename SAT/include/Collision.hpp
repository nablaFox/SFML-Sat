#pragma once

#include "Box.hpp"

constexpr float INF = std::numeric_limits<float>::infinity();

class Collision {
public:
    static Collision Instance;

    bool SATCollision(Box& boxA, Box& boxB);

    void CollisionAction(Box& boxA, Box& boxB);

private:

};