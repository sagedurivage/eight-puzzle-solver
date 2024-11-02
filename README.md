# eight-puzzle-solver
This project implements the A* search algorithm, with Misplaced Tile and Euclidean Distance heuristic options, and the Uniform Cost Search algorithm to solve the Eight Puzzle problem using C++.

## Features

- **Heuristic Options**:
  - Uniform Cost Search
  - A* Search with Misplaced Tile heuristic
  - A* Search with Euclidean Distance heuristic
- **Trace**: Outputs each step from the initial state to the goal.
- **Stats**: Provides statistics such as the total nodes expanded, the maximum number of nodes in the queue at any one time, and depth of the goal node.

## Setup

### Prerequisites
- **C++ Compiler**: Ensure you have a C++11 (or later) compatible compiler.

### Compilation

To compile the project, use the following command:

```bash
g++ -Iinclude -o EightPuzzleSolver main.cpp src/*.cpp -std=c++11
```

## Usage

After compiling, run the program:

```bash
./EightPuzzleSolver
```

### Program Options

1. Choose between the default puzzle or a custom puzzle input.
2. Select the search algorithm:
   - `1`: Uniform Cost Search
   - `2`: A* with Misplaced Tile heuristic
   - `3`: A* with Euclidean Distance heuristic

The program will output each step of the solution path and provide statistics on nodes expanded, solution depth, and maximum queue size.

## Example Output

```plaintext
Welcome to sduri001 8 puzzle solver.
Type "1" to use a default puzzle, or "2" to enter your own puzzle.
1
Enter your choice of algorithm
Uniform Cost Search
A* with the Misplaced Tile heuristic.
A* with the Euclidean distance heuristic.

3

Expanding state
1 2 3 
4 8 b 
7 6 5 

The best state to expand with g(n) = 1 and h(n) = 3 is...
1 2 3 
4 8 5 
7 6 b 
  Expanding this node...

The best state to expand with g(n) = 2 and h(n) = 3 is...
1 2 3 
4 8 5 
7 b 6 
  Expanding this node...

The best state to expand with g(n) = 3 and h(n) = 2 is...
1 2 3 
4 b 5 
7 8 6 
  Expanding this node...

The best state to expand with g(n) = 4 and h(n) = 1 is...
1 2 3 
4 5 b 
7 8 6 
  Expanding this node...


Goal!!!

To solve this problem the search algorithm expanded a total of
6 nodes.
The maximum number of nodes in the queue at any one time: 10.
The depth of the goal node was 5.
```

## Releases

Track progress through the project’s versioned releases in the **Releases** section of this repository.
