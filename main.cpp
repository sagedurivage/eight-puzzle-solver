
#include "include/solver.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// display preliminary prompts
int welcome()
{
    // welcome message
    cout << endl << "Welcome to sduri001 8 puzzle solver." << endl;

    // get user input
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
    // get each row (would use nested loop if not for "first," "second," "third" specs)
    size_t i = 0;
    cout << "Enter the first row, use space or tabs between numbers ";
    for (i = 0; i < 3; ++i)
    {
        cin >> puzzle[i];
    }
    cout << "Enter the second row, use space or tabs between numbers ";
    for (i = 0; i < 3; ++i)
    {
        cin >> puzzle[3 + i];
    }
    cout << "Enter the third row, use space or tabs between numbers ";
    for (i = 0; i < 3; ++i)
    {
        cin >> puzzle[6 + i];
    }

    return puzzle;
}

int main()
{
    int usrInput = welcome();

    // define initial state of puzzle
    vector<int> initialPuzzle(9, 0);
    if (usrInput == 1)
    {
        initiaPuzzle = {1, 2, 3, 4, 8, 0, 7, 6, 5}; // default puzzle
    }
    else
    {
        initialPuzzle = getPuzzle();
    }

    // define goal state of puzzle
    vector<int> solution = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    // FIXME
    // - choose search algorithm
    // - instantiate solver
    // - execute solver

    return 0;
}

