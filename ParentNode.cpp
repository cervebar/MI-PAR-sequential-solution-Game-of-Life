/* 
 * File:   ParentNode.cpp
 * Author: Babu
 * 
 * Created on 20. říjen 2012, 21:31
 */

#include "ParentNode.h"
#include "LeafNode.h"

ParentNode::ParentNode( int maxHammWeight,  int level, bool value) : Node(maxHammWeight, level, value) {
    this->isLeaf = false;
}

ParentNode::~ParentNode() {
}

Node* ParentNode::makeRightFalseNode() {    
    Node * n;
    int childMaxHammWeight = maxHammWeight - 1;
     int childLevel=level-1;
    if (childLevel==1 ) {//we make it at the last level so we now need the leafs
        n = new LeafNode(childMaxHammWeight, childLevel, false);
    } else {
        n = new ParentNode(childMaxHammWeight, childLevel, false);
    }
    return n;
}

Node* ParentNode::makeLeftTrueNode() {
    Node * n;
    int childMaxHammWeight = maxHammWeight;
     int childLevel=level-1;
    if (childLevel==1) {//we make it at the last level so we now need the leafs
        n = new LeafNode(childMaxHammWeight, childLevel, true);
    } else {
        n = new ParentNode(childMaxHammWeight, childLevel, true);
    }
    return n;
}
