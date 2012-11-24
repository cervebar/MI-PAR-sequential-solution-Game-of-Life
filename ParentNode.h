/* 
 * File:   ParentNode.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 21:31
 */

#ifndef PARENTNODE_H
#define	PARENTNODE_H

#include "Node.h"


class ParentNode : public Node{
public:
    ParentNode( int maxHammWeight, int level,bool value);
    virtual ~ParentNode();
    
    virtual Node* makeRightFalseNode();
    virtual Node* makeLeftTrueNode();    
    
private:

};

#endif	/* PARENTNODE_H */

