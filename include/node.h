
#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node
{
  private:
    vector<int> state;  // maintain puzzle state
    Node * mommy;       // maintain parent node
    int cost;           // maintain path cost
    int heur;           // maintain heuristic value

  public:
    // constructinator
    Node(const vector<int> & state, Node * parent = nullptr, int cost = 0, int heur = 0);
    // member functorinos
    const vector<int> & getState() const;   // access puzzle state at some node
    Node * getParent() const;               // access parent node of node
    int getCost() const;                    // access path cost to node
    int getHeur() const;                    // access heuristic of node
};

#endif

