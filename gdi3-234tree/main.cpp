// gdi3-234tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tree.h"
int main()
{
    ZdvTree *MemeTree = new ZdvTree();
    MemeTree->insertKey(1, 1);
    MemeTree->insertKey(5, 5);
    MemeTree->insertKey(3, 3);
    MemeTree->insertKey(4, 4);

    std::cout << "Hello World!\n";
}

