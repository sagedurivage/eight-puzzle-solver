
#ifndef SOLVER_H
#define SOLVER_H

#include "node.h"
#include "puzzle.h"
#include "heuristic.h"
#include <vector>
#include <string>

using namespace std;

class Solver
{
  private:
    Puzzle puzzle;
    int maxQueueSize = 0;
    int totNodesExpanded = 0;

    // helpful pointer funky
    // syntax citation: https://en.cppreference.com/w/cpp/language/pointer
    void aStar(int (*heuristic)(const Node &, const Puzzle &));   // run A* search algorithm
    // -> Heuristic::uniformCost()
    // -> Heuristic::misplacedTile()
    // -> Heuristic::euclideanDist()

    void trace(Node * goalNode);
    void attemptTrace(Node * goalNode);
    
  public:
    // constructinator
    Solver(const vector<int> & init, const vector<int> & goal);

    // rap star functorinos
    void uCostSearch();
    void aStarMis();
    void aStarEuc();
};

#endif

