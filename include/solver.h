
#ifndef SOLVER_H
#define SOLVER_H

#include "node.h"
#include "puzzle.h"
#include "heuristic.h"
#include <vector>
#include <string>

class Solver
{
  private:
    Puzzle puzzle;

    // helpful pointer funky
    // syntax citation: https://en.cppreference.com/w/cpp/language/pointer
    void aStar(int (*heuristic)(const Node &, const Puzzle &));   // run A* search algorithm
    // -> Heuristic::uniformCost()
    // -> Heuristic::misplacedTile()
    // -> Heuristic::euclideanDist()
    
  public:
    // constructinator
    Solver(const vector<int> & init, const vector<int> & goal);

    // rap star functorinos
    void uCostSearch();
    void aStarMis();
    void aStarEuc();
};

#endif

