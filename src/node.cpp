
#include "../include/node.h"
#include <iostream>

using namespace std;

// constructinator definition
Node::Node(const vector<int> & state, Node * parent, int cost, int heur)
    : state(state), mommy(parent), cost(cost), heur(heur)
{
}

/* funky definitions */

const vector<int> & Node::getState() const { return state; }

Node * Node::getParent() const { return mommy; }

int Node::getCost() const { return cost; }

int Node::getHeur() const { return heur; }

void Node::printState() const
{
    // print out state of puzzle in a 3x3 format
    for (size_t i = 0; i < (state.size() / 3); ++i)     // rows
    {
        for (size_t j = 0; j < (state.size() / 3); ++j) // columns
        {
            if (state[(i * 3) + j] == 0)
            {
                cout << "b ";
            }
            else
            {
                cout << state[(i * 3) + j] << " ";
            }
        }
        cout << endl;   // next row
    }
    // does NOT end with newline for trace syntax
}

