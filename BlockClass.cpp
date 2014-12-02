/*
* BlockClass.cpp
*/ 
using namespace std;

#include "BlockClass.h"
#include <string>
#include <iostream>

Block::Block(int s, int i) {
    tile_number = DEF_VAL_VAL;
    size = DEF_VAL_SIZE;
    SetSize(s);
    SetNumber(i);
}

void Block::SetSize(int s) {
    // if s == something we dont like cuz its GUI
    size = s;
}

void Block::SetNumber(int i) {
    if(i != 0 && i != 2 && i != 4 && i != 8 && i != 16 && i != 32 && i != 64
        && i != 128 && i != 256 && i != 512 && i != 1024 && i != 2048) {
        cout << "Error: Invalid number, please choose a number" << endl
        << "that is a power of 0 between 2 and 2048 and not 1" << endl;
    }
    else {
        tile_number = i;
    }
}

int Block::GetNumber() {
    return tile_number;
}

int Block::GetSize() {
    return size;
}