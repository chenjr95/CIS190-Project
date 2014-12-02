/*
* GridClass.cpp
*/ 

using namespace std;

#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "BlockClass.h"
#include "GridClass.h"

int Grid::UpdateGrid(string dir) {
    int change, i;
    int prev1[4], prev2[4], prev3[4], prev4[4];
    int merge1[4], merge2[4], merge3[4], merge4[4];
    if(dir == "w")
    {
        for(i = 0; i < DEF_VAL_GRID; i++)
        {
            prev1[i] = fullGrid.at(i).at(0).GetNumber();
            prev2[i] = fullGrid.at(i).at(1).GetNumber();
            prev3[i] = fullGrid.at(i).at(2).GetNumber();
            prev4[i] = fullGrid.at(i).at(3).GetNumber();
            merge1[i] = fullGrid.at(i).at(0).GetNumber();
            merge2[i] = fullGrid.at(i).at(1).GetNumber();
            merge3[i] = fullGrid.at(i).at(2).GetNumber();
            merge4[i] = fullGrid.at(i).at(3).GetNumber();
        }
        MergeTiles(merge1);
        MergeTiles(merge2);
        MergeTiles(merge3);
        MergeTiles(merge4);
        change = TestChange(prev1, prev2, prev3, 
            prev4, merge1, merge2, merge3, merge4);
        if(change == 1) {
            for(i = 0; i < DEF_VAL_GRID; i++) {
                fullGrid.at(i).at(0).SetNumber(merge1[i]);
                fullGrid.at(i).at(1).SetNumber(merge2[i]);
                fullGrid.at(i).at(2).SetNumber(merge3[i]);
                fullGrid.at(i).at(3).SetNumber(merge4[i]);
            }
            SpawnNewTile();
        }
    }
    else if(dir == "a")
    {
        for(i = 0; i < DEF_VAL_GRID; i++)
        {
            prev1[i] = fullGrid.at(0).at(i).GetNumber();
            prev2[i] = fullGrid.at(1).at(i).GetNumber();
            prev3[i] = fullGrid.at(2).at(i).GetNumber();
            prev4[i] = fullGrid.at(3).at(i).GetNumber();
            merge1[i] = fullGrid.at(0).at(i).GetNumber();
            merge2[i] = fullGrid.at(1).at(i).GetNumber();
            merge3[i] = fullGrid.at(2).at(i).GetNumber();
            merge4[i] = fullGrid.at(3).at(i).GetNumber();
        }
        MergeTiles(merge1);
        MergeTiles(merge2);
        MergeTiles(merge3);
        MergeTiles(merge4);
        change = TestChange(prev1, prev2, prev3, 
            prev4, merge1, merge2, merge3, merge4);
        if(change == 1) {
            for(i = 0; i < DEF_VAL_GRID; i++) {
                fullGrid.at(0).at(i).SetNumber(merge1[i]);
                fullGrid.at(1).at(i).SetNumber(merge2[i]);
                fullGrid.at(2).at(i).SetNumber(merge3[i]);
                fullGrid.at(3).at(i).SetNumber(merge4[i]);
            }
            SpawnNewTile();
        }
    }
    else if(dir == "s")
    {
        for(i = 0; i < DEF_VAL_GRID; i++)
        {
            prev1[i] = fullGrid.at(3-i).at(0).GetNumber();
            prev2[i] = fullGrid.at(3-i).at(1).GetNumber();
            prev3[i] = fullGrid.at(3-i).at(2).GetNumber();
            prev4[i] = fullGrid.at(3-i).at(3).GetNumber();
            merge1[i] = fullGrid.at(3-i).at(0).GetNumber();
            merge2[i] = fullGrid.at(3-i).at(1).GetNumber();
            merge3[i] = fullGrid.at(3-i).at(2).GetNumber();
            merge4[i] = fullGrid.at(3-i).at(3).GetNumber();
        }
        MergeTiles(merge1);
        MergeTiles(merge2);
        MergeTiles(merge3);
        MergeTiles(merge4);
        change = TestChange(prev1, prev2, prev3, 
            prev4, merge1, merge2, merge3, merge4);
        if(change == 1) {
            for(i = 0; i < DEF_VAL_GRID; i++) {
                fullGrid.at(3-i).at(0).SetNumber(merge1[i]);
                fullGrid.at(3-i).at(1).SetNumber(merge2[i]);
                fullGrid.at(3-i).at(2).SetNumber(merge3[i]);
                fullGrid.at(3-i).at(3).SetNumber(merge4[i]);
            }
            SpawnNewTile();
        }
    }
    else if(dir == "d")
    {
        for(i = 0; i < DEF_VAL_GRID; i++)
        {
            prev1[i] = fullGrid.at(0).at(3-i).GetNumber();
            prev2[i] = fullGrid.at(1).at(3-i).GetNumber();
            prev3[i] = fullGrid.at(2).at(3-i).GetNumber();
            prev4[i] = fullGrid.at(3).at(3-i).GetNumber();
            merge1[i] = fullGrid.at(0).at(3-i).GetNumber();
            merge2[i] = fullGrid.at(1).at(3-i).GetNumber();
            merge3[i] = fullGrid.at(2).at(3-i).GetNumber();
            merge4[i] = fullGrid.at(3).at(3-i).GetNumber();
        }
        MergeTiles(merge1);
        MergeTiles(merge2);
        MergeTiles(merge3);
        MergeTiles(merge4);
        change = TestChange(prev1, prev2, prev3, 
            prev4, merge1, merge2, merge3, merge4);
        if(change == 1) {
            for(i = 0; i < DEF_VAL_GRID; i++) {
                fullGrid.at(0).at(3-i).SetNumber(merge1[i]);
                fullGrid.at(1).at(3-i).SetNumber(merge2[i]);
                fullGrid.at(2).at(3-i).SetNumber(merge3[i]);
                fullGrid.at(3).at(3-i).SetNumber(merge4[i]);
            }
            SpawnNewTile();
        }
    }
    else if(dir == "r")
    {
        ResetGameState();
    }
    else if(dir == "q")
    {
        cout << "Thank you for playing our AmazeBalls game!!!" << endl;
        return 3;
    }
    else if(dir == "gibsonisbetterthanpm")
    {
        fullGrid.at(3).at(3).SetNumber(1024);
        fullGrid.at(3).at(2).SetNumber(1024);
    }
    else
    {
        cout << "Error please use wasd to choose a direction" << endl;
    }
    return CheckGame();
}

int Grid::CheckGame() {
    int i, j, loseGame;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(fullGrid.at(i).at(j).GetNumber() == 2048) {
                return 1;
            }
        }
    }
    loseGame = 2;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(fullGrid.at(i).at(j).GetNumber() == 0 || 
                fullGrid.at(i).at(j).GetNumber() == 
                fullGrid.at(i+1).at(j).GetNumber() || 
                fullGrid.at(i).at(j).GetNumber() == 
                fullGrid.at(i).at(j+1).GetNumber())
            {
                loseGame = 0;
            }
        }
        if(fullGrid.at(i).at(3).GetNumber() == 0 || 
            fullGrid.at(i).at(3).GetNumber() == 
            fullGrid.at(i+1).at(3).GetNumber())
        {
            loseGame = 0;
        }
        if(fullGrid.at(3).at(i).GetNumber() == 0 || 
            fullGrid.at(3).at(i).GetNumber() == 
            fullGrid.at(3).at(i+1).GetNumber())
        {
            loseGame = 0;
        }
    }
    if(fullGrid.at(3).at(3).GetNumber() == 0) 
    {
        loseGame = 0;
    }
    return loseGame;
}

void Grid::ResetGameState() {
    int i, j;
    score = 0;
    for(i = 0; i < DEF_VAL_GRID; i++)
    {
        for(j = 0; j < DEF_VAL_GRID; j++)
        {
            fullGrid.at(i).at(j).SetNumber(0);
        }
    }
    SpawnNewTile();
    SpawnNewTile();
}

int Grid::TestChange(int *prev1, int *prev2, int *prev3, int *prev4, int *merge1,
  int *merge2, int *merge3, int *merge4) {
  int i;
  for(i = 0; i < DEF_VAL_GRID; i++) {
    if(prev1[i] != merge1[i] || prev2[i] != merge2[i] || prev3[i] != merge3[i] 
      || prev4[i] != merge4[i]) {
      return 1;
    }
  }
  return 0;
}

void Grid::SpawnNewTile() {
    int blockVal, randNumber, x, y;
    blockVal = rand() % DEF_VAL_GRID;
    if(blockVal < 3) {
        blockVal = 2;
    } else blockVal = DEF_VAL_GRID;
    randNumber = rand() % 16;
    x = randNumber / DEF_VAL_GRID;
    y = randNumber % DEF_VAL_GRID;
    while(fullGrid.at(x).at(y).GetNumber() != 0) {
        randNumber = rand() % 16;
        x = randNumber / DEF_VAL_GRID;
        y = randNumber % DEF_VAL_GRID;
    }
    fullGrid.at(x).at(y).SetNumber(blockVal);
    score = score + blockVal;
}

void Grid::MergeTiles (int *a) {
  int i;
  int j;
  for(i = 0; i < 3; i++) 
  {
    j = i + 1;
    while(j < 3 && a[j] == 0)
    {
      j++;
    }
    if(a[i] == 0 && a[j] != 0) {
      a[i] = a[j];
      a[j] = 0;
      i--;
    } 
    else if(a[i] == a[j])
    {
      a[i] = a[i] * 2;
      a[j] = 0;
    } 
    else if(i == j-1)
    {
      a[i+1] = a[j];
    }
    else 
    {
      a[i+1] = a[j];
      a[j] = 0;
    }
  }
}

int Grid::GetScore() {
    return score;
}

void Grid::PrintGrid() {
    int i, j, width1, width2;
    cout << endl << endl << endl << endl << endl << endl;
    cout << setw(BOARD_WIDTH) << setfill('-') << "" << setfill(' ') << endl;
    for(i = 0; i < DEF_VAL_GRID; i++)
    {
        PrintBlankLines();
        for(j = 0; j < DEF_VAL_GRID; j++)
        {
            if(fullGrid.at(i).at(j).GetNumber() < 10)
            {
                width1 = SINGLE_DIGIT;
                width2 = SINGLE_DIGIT;
            }
            else if(fullGrid.at(i).at(j).GetNumber() < 100)
            {
                width1 = DOUBLE_DIGIT;
                width2 = SINGLE_DIGIT;
            }
            else if(fullGrid.at(i).at(j).GetNumber() < 1000)
            {
                width1 = TRIPLE_DIGIT;
                width2 = TRIPLE_DIGIT;
            }
            else 
            {
                width1 = QUAD_DIGIT;
                width2 = TRIPLE_DIGIT;
            }
            if(fullGrid.at(i).at(j).GetNumber() != 0)
            {
                cout << "|" << setw(width1) << "" 
                << GetNumberColor(fullGrid.at(i).at(j).GetNumber()) 
                << fullGrid.at(i).at(j).GetNumber() << RESET 
                << setw(width2) << "";
            }
            else
            {
                cout << "|" << setw(width1) << "" 
                << " " << setw(width2) << "";
            }
        }
        cout << "|" << endl;
        PrintBlankLines();
        cout << setw(BOARD_WIDTH) << setfill('-') << "" << endl;
    }
}

string Grid::GetNumberColor(int number) {
    if(number == 2) 
    {
        return RED;
    }
    else if(number == 4) 
    {
        return GREEN;
    }
    else if(number == 8) 
    {
        return YELLOW;
    }
    else if(number == 16) 
    {
        return BLUE;
    }
    else if(number == 32)
    {
        return MAGENTA;
    }
    else if(number == 64)
    {
        return CYAN;
    }
    else if(number == 128)
    {
        return BLACK;
    }
    else if(number == 256)
    {
        return RED;
    }
    else if(number == 512)
    {
        return GREEN;
    }
    else if(number == 1024)
    {
        return BLUE;
    }
    else
    {
        return CYAN;
    }
}

void Grid::PrintBlankLines() {
    int i, j;
    for(i = 0; i < BLANK_SPACE; i++)
    {
        for(j = 0; j < DEF_VAL_GRID; j++)
        {
            cout << setfill(' ') << "|" << setw(BLOCK_WIDTH) << "";
        }
        cout << "|" << endl;
    }
}

Grid::Grid() {
    fullGrid.resize(DEF_VAL_GRID);
    int i, j;
    score = 0;
    for(i = 0; i < DEF_VAL_GRID; i++)
    {
        for(j = 0; j < DEF_VAL_GRID; j++)
        {
            fullGrid.at(i).push_back(Block(DEF_VAL_SIZE, DEF_VAL_VAL));
        }
    }
    SpawnNewTile();
    SpawnNewTile();
}