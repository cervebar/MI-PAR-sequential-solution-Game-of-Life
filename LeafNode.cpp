/* 
 * File:   LeafNode.cpp
 * Author: Babu
 * 
 * Created on 20. říjen 2012, 21:22
 */

#include "LeafNode.h"

LeafNode::LeafNode( int maxHammWeight,  int level, bool value) : Node(maxHammWeight, level, value) {
    this->isLeaf = true;
}

LeafNode::~LeafNode() {
}

//TODO pomoci vyjimky

Node* LeafNode::makeLeftTrueNode() {
    cerr << "CAN´T build new node this is LEAF!" << endl;
    return NULL;
}

//TODO pomoci vyjimky

Node* LeafNode::makeRightFalseNode() {
    cerr << "CAN´T build new node this is LEAF!" << endl;
    return NULL;
}

