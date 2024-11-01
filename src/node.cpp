
#include "../include/node.h"

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

