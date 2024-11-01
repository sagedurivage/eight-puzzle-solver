
#include "../include/heuristic.h"
#include <cmath>

// Uniform Cost is A* with heuristic of zero (from project outline note)
int Heuristic::uniformCost(const Node & node, const Puzzle & puzzle) { return 0; }

// Count number of tiles in current state NOT matching goal state
int Heuristic::misplacedTile(const Node & node, const Puzzle & puzzle)
{
    int cnt = 0;                                    // count
    const vector<int> & curr = node.getState();     // access (ref to) current node's state
    const vector<int> & goal = puzzle.getGoal();    // know (ref to) where we're going

    // iterate through ea. number of puzzle & increment count for ea. NOT matching position 
    // in goal state
    for (size_t i = 0; i < curr.size(); ++i)
    {
        if (curr[i] != goal[0] && curr[i] != 0)
        {
            cnt++;
        }
    }

    return cnt;
}

// Let's get hypotenuse!
int Heuristic::euclideanDist(const Node & node, const Puzzle & puzzle)
{
    // FIXME bruh idk rn
    return 1;
}

