
#include "../include/solver.h"
#include <iostream>

// constructinator definition
Solver::Solver(const vector<int> & init, const vector<int> & goal)
    : puzzle(init, goal)
{
}

/* rap stars (functions) in my spotify wrapped (program) */

void Solver::uCostSearch() { aStar(Heuristics::uniformCost); }

void Solver::aStarMis() { aStar(Heuristic::misplacedTile); }

void Solver::aStarEuc() { aStar(Heuristic::euclideanDist); }

// A* search algorithm
void Solver::aStar(int (*heuristic)(const Node &, const Puzzle &))
{
    // FIXME
}

