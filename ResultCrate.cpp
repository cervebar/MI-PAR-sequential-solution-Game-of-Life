/* 
 * File:   ResultCrate.cpp
 * Author: Babu
 * 
 * Created on 20. říjen 2012, 21:01
 */

#include "ResultCrate.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

ResultCrate::ResultCrate(TaskCrate* task, BinaryVector* bv,  int hammDistance,  int hammWeight, bool existResult) {
    this->task=task;
    this->hammingDistance = hammDistance;
    this->hammingWeight = hammWeight;
    this->existResult = existResult;    
    this->result=bv;
}

ResultCrate::ResultCrate(TaskCrate* task) {
    this->existResult = false;
    this->task=task;
    this->result=new BinaryVector();
}

/**
 * ! we have to delete start configuration somewhere elese
 */
ResultCrate::~ResultCrate() {
    delete result;
    delete task;
}

void ResultCrate::printResult() {
    cout << "RESULT===============================================" << endl;   
    task->printTaskCrate();
    
    if (existResult) {
        cout << "RESULT:" << endl;
        result->printVector();
        cout << "hammDistance:" << hammingDistance << ", hamming weight: " << hammingWeight << endl;
    } else {
        cout << "Solution does not exist." << endl;
    }
}

