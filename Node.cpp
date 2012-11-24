/* 
 * File:   Node.cpp
 * Author: Babu
 * 
 * Created on 20. říjen 2012, 21:14
 */

#include "Node.h"

Node::Node( int maxHammWeight,  int level, bool value) {
    this->maxHammWeight = maxHammWeight;
    this->level = level;
    this->value = value;
}

Node::~Node() {
}

void Node::printNode() {
    if (isLeaf) {
        cout << "LEAF:  ";
    } else {
        cout << "PARENT:";
    }
    cout << " value=" << value << " maximalHammWeight= " << maxHammWeight << ", level= " << level << endl;
}





