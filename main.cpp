
#include "include/solver.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// get user's choice of initial puzzle
int welcome()
{
    cout << endl << "Welcome to sduri001 8 puzzle solver." << endl;

    int input = 0;
    while (input != 1 && input != 2)
    {
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> input;
    }

    return input;
}

// get user-defined initial state of puzzle
vector<int> getPuzzle()
{
    vector<int> puzzle(9, 0);
    cout << "Enter your puzzle, use a zero to represent the blank" << endl;
    // get each row
    cout << "Enter the first row, use space or tabs between numbers ";
    cin >> puzzle[0] >> puzzle[1] >> puzzle[2];
    cout << "Enter the second row, use space or tabs between numbers ";
    cin >> puzzle[3] >> puzzle[4] >> puzzle[5];
    cout << "Enter the third row, use space or tabs between numbers ";
    cin >> puzzle[6] >> puzzle[7] >> puzzle[8];
    cout << endl;

    return puzzle;
}

// get user's choice of search algorithm
int algoChoice()
{
    cout << "Enter your choice of algorithm" << endl;
    cout << "Uniform Cost Search" << endl;
    cout << "A* with the Misplaced Tile heuristic." << endl;
    cout << "A* with the Euclidean distance heuristic." << endl << endl;

    int input = 0;
    cin >> input;

    // meager input validation :-(
    while (input != 1 && input != 2 && input != 3)
    {
    cout << "(Type \"1,\" \"2,\" or \"3\")" << endl;
    cin >> input;
    }

    return input;
}

int main()
{
    int usrInput = welcome();

    // define initial state of puzzle
    vector<int> initialPuzzle(9, 0);
    if (usrInput == 1)
    {
        // initialPuzzle = {1, 2, 3, 4, 8, 0, 7, 6, 5};    // default puzzle
        // initialPuzzle = {1, 2, 3, 4, 5, 6, 7, 8, 0};    // trivial (0)
        // initialPuzzle = {1, 2, 3, 4, 5, 6, 7, 0, 8};    // very easy (1)
        // initialPuzzle = {1, 2, 0, 4, 5, 3, 7, 8, 6};    // easy (2)
        // initialPuzzle = {0, 1, 2, 4, 5, 3, 7, 8, 6};    // doable (3)
        // initialPuzzle = {8, 7, 1, 6, 0, 2, 5, 4, 3};    // oh boy (4)
        initialPuzzle = {1, 2, 3, 4, 5, 6, 8, 7, 0};    // impossible (5)
    }
    else
    {
        initialPuzzle = getPuzzle();
    }

    // define goal state of puzzle
    vector<int> solution = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    // instantiate solver
    Solver solutionist(initialPuzzle, solution);

    usrInput = algoChoice();
    if (usrInput == 1)
    {
        solutionist.uCostSearch();
    }
    else if (usrInput == 2)
    {
        solutionist.aStarMis();
    }
    else if (usrInput == 3)
    {
        solutionist.aStarEuc();
    }

    return 0;
}

