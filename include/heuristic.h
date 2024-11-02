
#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "node.h"
#include "puzzle.h"

using namespace std;

class Heuristic
{
  public:
    // do not feel like defining a constructor for instantiation -> static we go
    static int uniformCost(const Node & node, const Puzzle & puzzle);
    static int misplacedTile(const Node & node, const Puzzle & puzzle);
    static int euclideanDist(const Node & node, const Puzzle & puzzle);
};

#endif

