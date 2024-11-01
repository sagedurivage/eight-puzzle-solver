
#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>

using namespace std;

class Puzzle
{
  private:
    vector<int> init;   // initial state of puzzle
    vector<int> goal;   // goal state of puzzle

  public:
    // constructinator
    Puzzle(const vector<int> & init, const vector<int> & goal);
    // member functorinos
    const vector<int> & getInitial() const;     // access iniital state of puzzle
    const vector<int> & getGoal() const;        // access goal state
    bool solved(const vector<int> state) const; // check if goal state reached
};

#endif

