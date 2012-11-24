/* 
 * File:   Worker.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 22:53
 */

#ifndef WORKER_H
#define	WORKER_H

#include "TaskCrate.h"
#include "Node.h"
#include "ResultCrate.h"
#include <stack>

class Worker {
public:
    Worker(TaskCrate* task, bool* starArray, Node* startNode, bool verbose);
    virtual ~Worker();
    void work();

    ResultCrate* getResult() const {
        return result;
    }
    
    ResultCrate* getSmallMistakeResult() const {
        return smallMistakeResult;
    }


private:
    TaskCrate* task;
    bool* helpArray;
    bool verbose;
    int sizeOfHelpArray;
    int treeLevel;
    stack<Node*> stacik;
    //explicit match
    int bestHammWeight;
    ResultCrate* result;
    //implicit match
    int bestHammWeightSmallMistake;
    ResultCrate* smallMistakeResult;

    void playGameOfLife(Node* node);
    void saveResult(BinaryVector* result);

    //FUNCTIONS AND FIELDS TO PRINT INFORMATIONS WHEN VERBOSE IS TRUE------------------ 
    int iterations;
    int countOfLeafs;

    void printIsEmptyStack();
    void printNothing();
    void printHammWeights(int const nodeHamm);
    void printThrowingAway(Node* node);
    void printWritingvalue(bool value, int pointer);
    void printHelpArray();
    void printIsLeaf(bool isLeaf);
    void printPopStack(Node* node);
    void printStartWorkIteration();
    void printAddToStack(Node* leftTrue, Node* rightfalse);
    void printEndingState();
    void printStartState();
    void printExplicitMatch();
    void printImplicitMatch(int distance);
    void printChangeResult(int weight);
    void printNoChange();
    void printImplicitChangeResult(int bvWeight);
    void printPlaygame();
};

#endif	/* WORKER_H */

