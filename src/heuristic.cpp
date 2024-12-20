
#include "../include/heuristic.h"
#include <cmath>

using namespace std;

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
        if (curr[i] != goal[i] && curr[i] != 0)
        {
            cnt++;
        }
    }

    return cnt;
}

// Let's get hypotenuse!
// formula source: https://en.wikipedia.org/wiki/Euclidean_distance (2-dimensional)
int Heuristic::euclideanDist(const Node & node, const Puzzle & puzzle)
{
    int dist = 0;
    const vector<int> & curr = node.getState();     // access (ref to) current node's state
    const vector<int> & goal = puzzle.getGoal();    // know (ref to) where we're going

    // iterate through each element of current puzzle state
    for (size_t i = 0; i < curr.size(); ++i)
    {
        if (curr[i] != 0)   // disregard empty space in puzzle
        {
            // identify index of element in solution
            int goalIndex = 0;
            while (curr[i] != goal[goalIndex])
            {
                ++goalIndex;
            }

            // get positions on puzzle grid
            int currRow = i / 3;    // rows 0, 1, 2
            int currCol = i % 3;    // columns 0, 1, 2
            int goalRow = goalIndex / 3;
            int goalCol = goalIndex % 3;
            // calculate euclidean distance between indices
            dist += sqrt(((currRow - goalRow) * (currRow - goalRow)) +
                         ((currCol - goalCol) * (currCol - goalCol)));
        }
    }

    return dist;
}

