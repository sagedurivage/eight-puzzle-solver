
#include "../include/solver.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

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
    cout << endl << "Expanding state" << endl;
    solutionPath[0]->printState();
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
    cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
    cout << "The depth of the goal node was " << solutionPath.size() - 1 << "." << endl;
}

void Solver::attemptTrace(Node * failure)
{
    vector<Node *> attemptPath;

    // get sequence of nodes up to the initial state through parents
    for (Node * curr = failure; curr != nullptr; curr = curr->getParent())
    {
        attemptPath.push_back(curr);
    }

    cout << endl << "Impossible to solve." << endl;
    cout << "In its attempt to solve this problem the search algorithm expanded a total of" << endl;
    cout << attemptPath.size() << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
    cout << "The depth of the failure node was " << attemptPath.size() - 1 << "." << endl;
}

// need some functionality to compare nodes in the queue
// syntax source: https://www.geeksforgeeks.org/custom-comparator-in-priority_queue-in-cpp-stl/#
struct NodeComparison
{
    bool operator()(const Node * ln, const Node * rn) const
    {
        return (ln->getCost() + ln->getHeur()) > (rn->getCost() + rn->getHeur());   // > for min-heap
    }
};

// A* search algorithm
// syntax source: https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/#
// syntax source: https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
// syntax source: https://www.geeksforgeeks.org/cpp-for-loop/# (range-based)
void Solver::aStar(int (*heuristic)(const Node &, const Puzzle &))
{
    // there was a good quiz question about optimal ordering of nodes to expand efficiently
    priority_queue<Node *, vector<Node *>, NodeComparison> frontier;
    // maintain explored states
    set<vector<int>> repeats;

    // create a node for the initial state of the puzzle & push to queue
    Node * startNode = new Node(puzzle.getInitial(), nullptr, 0, heuristic(puzzle.getInitial(), puzzle));
    frontier.push(startNode);

    Node * curr = nullptr;
    while (!frontier.empty())
    {
        // keep track of maximum queue size for trace
        if (frontier.size() > maxQueueSize)
        {
            maxQueueSize = frontier.size();
        }

        curr = frontier.top();
        frontier.pop();

        // check if puzzle is solved
        if (puzzle.solved(curr->getState()))
        {
            trace(curr);    // print trace for solution
            return;         // and exit
        }

        // current state is NOT solution -> add to explored set
        repeats.insert(curr->getState());

        // iterate through possible successive states
        for (const auto & nState : puzzle.getLineage(curr->getState()))
        {
            // check if state is a repeat; skip following, if so
            if (repeats.find(nState) != repeats.end()) continue;

            // build a valid state its very own node! wow!
            Node * child = new Node(nState, curr, (curr->getCost() + 1), heuristic(nState, puzzle));

            // PUT THAT CHILD ON THE FRONT LINES!!!
            frontier.push(child);
        }
    }

    // if no goal state reached in the while loop
    attemptTrace(curr);
}

