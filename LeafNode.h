/* 
 * File:   LeafNode.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 21:22
 */

#ifndef LEAFNODE_H
#define	LEAFNODE_H

#include "Node.h"


class LeafNode : public Node{
public:
    LeafNode( int maxHammWeight, int level,bool value);    
    virtual ~LeafNode();
    
   virtual Node* makeRightFalseNode();
   virtual Node* makeLeftTrueNode();
    
    
private:

};

#endif	/* LEAFNODE_H */

