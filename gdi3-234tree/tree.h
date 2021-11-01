#pragma once
/**
 * @brief Offizielle 2-3-4-Baum C++-Headerdatei mit t=2
 * @version 1.0 - Erste Version
 * @authors Dominik Müller, Marius Witte, Melik Avcu, Philipp Dittmer
 */

#ifndef ZDV_TREE_H
#define ZDV_TREE_H

typedef struct Node {
    int keyCount; // kann nur die Werte 1, 2 oder 3 annehmen
    int key[3];
    int value[3];
    Node* child[4];  // bei bis zu 3 Schlüsseln können bis zu 4 Teilbäume verwaltet werden
}Node;

typedef struct Result {
    Node* node;
    int index; // Index des gefundenen Elements
    bool success;
    int comparisons;
}Result;

class ZdvTree {
private:
    Node* root;

public:
    ZdvTree();
    ~ZdvTree();
    Result insertKey(int key, int value);
    Result searchKey(int key);
};

#endif // ZDV_TREE_H