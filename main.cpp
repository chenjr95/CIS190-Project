/*
* main.cpp
*/

using namespace std;

#include <vector>
#include <iostream>
#include <string>
#include "BlockClass.h"
#include "GridClass.h"

int main() {
    Grid gameGrid;
    int endGame = 0;
    string input;
    gameGrid.PrintGrid();
    cout << "Your score is currently: " << gameGrid.GetScore() << endl;
    while(endGame == 0) {
        cout << "Please enter wasd for direction, q to quit, or r to restart"
            << endl;
        cin >> input;
        endGame = gameGrid.UpdateGrid(input);
        gameGrid.PrintGrid();
        cout << "Your score is currently: " << gameGrid.GetScore() << endl;
    }
    if(endGame == 1)
    {
        cout << "Congratulations, you win!" << endl;
    }
    else if(endGame == 2)
    {
        cout << "Sorry, you lose!" << endl;    
    }
    else
    {
        cout << "U R A Quitter!" << endl;
    }

    return 0;
}
