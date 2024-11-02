
#include "../include/solver.h"
#include <iostream>
#include <algorithm>

using namespace std;

// constructinator definition
Solver::Solver(const vector<int> & init, const vector<int> & goal)
    : puzzle(init, goal)
{
}

/* rap stars (functions) in my spotify wrapped (program) */

void Solver::uCostSearch() { aStar(Heuristic::uniformCost); }

void Solver::aStarMis() { aStar(Heuristic::misplacedTile); }

void Solver::aStarEuc() { aStar(Heuristic::euclideanDist); }

// trace
void Solver::trace(Node * goal)
{
    vector<Node *> solutionPath;

    // get sequence of nodes up to the initial state through parents
    for (Node * curr = goal; curr != nullptr; curr = curr->getParent())
    {
        solutionPath.push_back(curr);
    }

    // ti esrever dna ti pilf  |  flip it and reverse it
    reverse(solutionPath.begin(), solutionPath.end());

    // output trace
    cout << "Expanding state" << endl;
    solutionPath[0]->printState();
    cout << endl;
    // iterate through each node in the vector
    for (size_t i = 1; i < (solutionPath.size() - 1); ++i)
    {
        cout << endl << "The best state to expand with g(n) = "
             << solutionPath[i]->getCost() << " and h(n) = " 
             << solutionPath[i]->getHeur() << " is..." << endl;
        solutionPath[i]->printState();
        cout << "  Expanding this node..." << endl;
    }
    cout << endl << endl << "Goal!!!" << endl;
    cout << endl << "To solve this problem the search algorithm expanded a total of" << endl;
    cout << solutionPath.size() << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << "FIXME." << endl;
    cout << "The depth of the goal node was " << solutionPath.size() - 1 << endl;
}

// need some functionality to compare nodes in the queue

// looking into syntax of priority queue
// syntax source: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/#

// A* search algorithm
void Solver::aStar(int (*heuristic)(const Node &, const Puzzle &))
{
    // FIXME
}

