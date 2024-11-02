
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

// syntax source: https://www.geeksforgeeks.org/cpp-for-loop/# (range-based)
vector<vector<int>> Puzzle::getLineage(const vector<int> & state) const
{
    vector<vector<int>> lineage;

    // identify index of missing piece
    int bIndex = 0;
    while (state[bIndex] != 0)
    {
        ++ bIndex;
    }
    int bRow = bIndex / 3;  // rows 0, 1, 2
    int bCol = bIndex % 3;  // columns 0, 1, 2

    // up down left right A B A B
    const vector<pair<int, int>> bMoves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    for (const auto & [rowMove, colMove] : bMoves)
    {
        int nRow = bRow + rowMove;
        int nCol = bCol + colMove;

        // check blank isn't on some 'edge' or 'corner'
        if (nRow >= 0 && nRow < 3 && nCol >= 0 && nCol < 3)
        {
            int nIndex = (nRow * 3) + newCol;

            // build a new state for a legal move
            vector<int> offspring = state;
            // swap elements at respective indices
            int tmp = offspring[bIndex];
            offSpring[bIndex] = offspring[nIndex];
            offSpring[nIndex] = tmp;

            // include new state is list of possible successors
            lineage.push_back(offspring);
        }
    }

    return lineage;
}

