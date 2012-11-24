/* 
 * File:   Node.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 21:14
 */

#ifndef NODE_H
#define	NODE_H

#include "BinaryVector.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
    Node( int maxHammWeight, int level,bool value);   
    virtual ~Node();
    
    void printNode();
    
    virtual Node* makeRightFalseNode()=0;
    virtual Node* makeLeftTrueNode()=0;
    
        
    //GETTERS AND SETTERS---------------------------------------------------------
    int getMaximalHammWeight() const {
        return maxHammWeight;
    }

     int getLevel() const {
        return level;
    }
    bool isIsLeaf() const {
        return isLeaf;
    }

    bool getValue() const {
        return value;
    }

    
protected:
    int maxHammWeight;
     int level;
    bool isLeaf;
    bool value;
private:

};

#endif	/* NODE_H */

