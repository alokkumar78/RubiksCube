#include <bits/stdc++.h>
#include "RubiksCube3dArray.cpp"
#include "RubiksCube.cpp"

#include "DFSSolver.h"



using namespace std;

int main() {

// DFS Solver Testing
   RubiksCube3dArray cube;
   cout<<"Representing a solved cube : \n";
   cube.print();

   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);

   cout<<"cubes are randomly shuffled as follows (6 times) :  ";
   for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
   cout << "\n";
   cout<<"Here is visual representation of shuffled cube:  \n";
   cube.print();

   cout<<"\n\n";
   cout<<"Steps to solve the shuffled cube:  ";
   DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
   vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
   cout<<"{   ";
   for (auto move: solve_moves) cout << cube.getMove(move) << " ";
   cout<<"     }\n";
   cout << "\n\n\n";
   // dfsSolver.rubiksCube.print();

    return 0;
}