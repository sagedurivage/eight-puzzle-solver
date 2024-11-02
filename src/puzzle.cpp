
#include "../include/puzzle.h"

using namespace std;

// constructinator definition
Puzzle::Puzzle(const vector<int> & init, const vector<int> & goal)
    : init(init), goal(goal)
{
}

/* funky definitions */

const vector<int> & Puzzle::getInitial() const { return init; }

const vector<int> & Puzzle::getGoal() const { return goal; }

bool Puzzle::solved(const vector<int> state) const { return state == goal; }    // == operator for vector

