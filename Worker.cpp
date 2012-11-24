/* 
 * File:   Worker.cpp
 * Author: Babu a Bouchy
 * 
 * Created on 20. říjen 2012, 22:53
 */

#include "Worker.h"
#include "ParentNode.h"

Worker::Worker(TaskCrate* task, bool* startArray, Node* startNode, bool verbose) {
    this->task = task;
    this->helpArray = startArray;
    this->verbose = verbose;
    this->sizeOfHelpArray = task->GetHeight() * task->GetWidth();
    this->treeLevel = task->GetHeight() * task->GetWidth();
    this->bestHammWeight = -1;
    this->result=new ResultCrate(task);
    this->bestHammWeightSmallMistake=-1;
    this->smallMistakeResult=new ResultCrate(new TaskCrate(task));

    if (startNode == NULL) {
        Node * leftTrue = new ParentNode(sizeOfHelpArray, sizeOfHelpArray, true);
        Node * rightFalse = new ParentNode(sizeOfHelpArray - 1, sizeOfHelpArray, false);
        stacik.push(rightFalse);
        stacik.push(leftTrue);
    } else {
        stacik.push(startNode);
    }
    //helping fields
    this->iterations = 1;
    this->countOfLeafs = 0;
}

Worker::~Worker() {
    delete helpArray;      
}

void Worker::work() {
    verbose ? printStartState() : printNothing();

    while (stacik.size() != 0) {
        verbose ? printStartWorkIteration() : printNothing();
        //1 take from the top of stack----------------------------------------------
        Node* node = stacik.top();
        stacik.pop();
        verbose ? printPopStack(node) : printNothing();
        //2 if the bestHamming weight is greater than can ever be in this branch
        //  we can throw this subtree away.-----------------------------------------
        verbose ? printHammWeights(node->getMaximalHammWeight()) : printNothing();
        if (node->getMaximalHammWeight() <= bestHammWeight) {
            verbose ? printThrowingAway(node) : printNothing();
            delete node;
            continue;
        }
        //3 set up the pointer / the max level versus node level--------------------
         int pointer = this->treeLevel - node->getLevel();
        //4 there where the pointer shows write the value
        this->helpArray[pointer] = node->getValue();
        verbose ? printWritingvalue(node->getValue(), pointer) : printNothing();
        //5 is the node LEAF?
        verbose ? printIsLeaf(node->isIsLeaf()) : printNothing();
        printNothing();
        if (node->isIsLeaf()) {
            playGameOfLife(node);
        } else {
            Node * leftTrue = node->makeLeftTrueNode();
            Node * rightFalse = node->makeRightFalseNode();
            verbose ? printAddToStack(leftTrue, rightFalse) : printNothing();
            stacik.push(rightFalse);
            stacik.push(leftTrue);
        }
        delete node;
        verbose ? printIsEmptyStack() : printNothing();

    };
    int i=0;
    verbose ? printEndingState() : printNothing();
}

void Worker::playGameOfLife(Node* node) { 
    verbose?printPlaygame():printNothing();
    
    BinaryVector* bv;
    bv = new BinaryVector(helpArray, task->GetWidth(), task->GetHeight());
    bv->iterateForQTimes(task->GetIterations());
    verbose ? bv->printVector() : printNothing();


    int distance = BinaryVector::hammingStartArrayDistance(bv, task->getResultingConfigurationVector());

    //final configurations are the same
    if (BinaryVector::equals(bv, task->getResultingConfigurationVector())) {
        verbose ? printExplicitMatch() : printNothing();
        int bvWeight = BinaryVector::hammingStartArrayWeight(bv);
        if (bvWeight > bestHammWeight) {
            verbose ? printChangeResult(bvWeight) : printNothing();
            bestHammWeight = bvWeight;
            result->setExistResult(true);
            result->setHammingDistance(distance);
            result->setHammingWeight(bvWeight);
            result->setResult(new BinaryVector(bv));
        }

    }//final configuration is not the same but the mistake is small
    else if (distance <= task->GetAMistake()) {
        verbose ? printImplicitMatch(distance) : printNothing();
        int bvWeight = BinaryVector::hammingStartArrayWeight(bv);
        if (bvWeight > bestHammWeightSmallMistake) {
            verbose ? printImplicitChangeResult(bvWeight) : printNothing();
            bestHammWeightSmallMistake = bvWeight;
            smallMistakeResult->setExistResult(true);
            smallMistakeResult->setHammingDistance(distance);
            smallMistakeResult->setHammingWeight(bvWeight);
            smallMistakeResult->setResult(new BinaryVector(bv));
        }               
    }//nothing changed
    else {
        verbose ? printNoChange() : printNothing();
    }
    delete bv;
}

//FUNCTIONS TO PRINT INFRMATIONS WHEN VERBOSE IS TRUE---------------------------

/**
 * This function is called in the case the verbose is false. Simply prints nothing.
 * The reason, why we have this function is that, we want to have the verbose
 * functionality with the good looking and good readable code. Now we can use
 * the ternary operator in this way: verbose ? printSomething() : printNothing();
 */
void Worker::printNothing() {
}

void Worker::printPlaygame(){
    cout << "Playing game!" << endl;
}

void Worker::printImplicitChangeResult(int weight){
    cout << "  ====b:" << bestHammWeightSmallMistake << "<" << weight
            << " changing small mistake result to this=========" << endl << endl;
}

void Worker::printNoChange() {
    cout << "  ---- no change -----------" << endl << endl;

}

void Worker::printChangeResult(int weight) {
    cout << "  ====b:" << bestHammWeight << "<" << weight
            << " changing result to this=========" << endl << endl;
}

void Worker::printImplicitMatch(int distance) {
    cout << "  !!!!!!!!!!!IMPLICIT MATCH - the mistake is " << distance << " <= " << task->GetAMistake() << endl;
}

void Worker::printExplicitMatch() {
    cout << "  !!!!!!!!!!!EXPLICIT MATCH - configurations are the same" << endl;
}

void Worker::printStartState() {
    cout << "==START==================================================" << endl;
    printIsEmptyStack();
    cout << "Iterations: " << iterations << " count of LEAFS: " << countOfLeafs << endl;
    task->printTaskCrate();
    cout << "=========================================================" << endl;

}

void Worker::printEndingState() {
    cout << "ENDING STATE======================================================================" << endl;
    printIsEmptyStack();
    cout << "Iterations: " << iterations << " count of LEAFS: " << countOfLeafs << endl;
    cout << "==================================================================================" << endl;

}

void Worker::printAddToStack(Node* leftTrue, Node* rightfalse) {
    cout << "6b) adding to stack: treelevel" << endl;
    cout << "     --- ";
    rightfalse->printNode();
    cout << "     --- ";
    leftTrue->printNode();
}

void Worker::printStartWorkIteration() {
    cout<<endl;
    cout << "0:------------------ Start new iteration: " << iterations <<
            ".-------------------" << endl;
    iterations++;
}

void Worker::printPopStack(Node* node) {
    cout << "1: Pop stack: ";
    node->printNode();
}

void Worker::printIsLeaf(bool isLeaf) {
    if (isLeaf) {
        cout << "5: this is leaf node" << endl;
        countOfLeafs++;
    } else {
        cout << "5: this is parent node" << endl;
    }
}

void Worker::printWritingvalue(bool value, int pointer) {
    cout << "3,4: Writing value " << value << " at position " << pointer << ":" << endl;
    printHelpArray();
}

void Worker::printHelpArray() {
    cout << "   HELP ARRAY: ";
    for (int i = 0; i < sizeOfHelpArray; i++) {
        cout << helpArray[i];
    }
    cout << endl;
}

void Worker::printIsEmptyStack() {
    cout << "6: Stack size: " << stacik.size() << endl;
}

void Worker::printHammWeights(const int nodeHamm) {
    string operatorH = "";
    if (nodeHamm <= bestHammWeight) {
        operatorH = " <= ";
    } else {
        operatorH = " > ";
    }
    cout << "2: Hamm weights node:" << nodeHamm << operatorH << "best:" << bestHammWeight << endl;
}

void Worker::printThrowingAway(Node* node) {
    cout << "----- Throwing node away - smaller Hammm weight: ";
    node->printNode();
}




