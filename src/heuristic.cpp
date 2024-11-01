
#include "../include/heuristic.h"
#include <cmath>

// Uniform Cost is A* with heuristic of zero
int Heuristic::uniformCost(const Node & node, const Puzzle & puzzle) { return 0; }

// Count number of tiles in current state NOT matching goal state
int Heuristic::misplacedTile(const Node & node, const Puzzle & puzzle)
{
    // FIXME
    return 1;
}

// Let's get hypotenuse!
int Heuristic::euclideanDist(const Node & node, const Puzzle & puzzle)
{
    // FIXME
    return 1;
}

