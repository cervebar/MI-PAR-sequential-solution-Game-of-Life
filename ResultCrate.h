/* 
 * File:   ResultCrate.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 21:01
 */

#ifndef RESULTCRATE_H
#define	RESULTCRATE_H

#include "BinaryVector.h"
#include "TaskCrate.h"

class ResultCrate {
public:
    ResultCrate(TaskCrate* task, BinaryVector* result,  int hammDistance,  int hammWeight, bool existResult);
    ResultCrate(TaskCrate* task);
    virtual ~ResultCrate();

    void printResult();

    //GETTERS AND SETTERS-------------------------------------

    BinaryVector* GetResultVector() const {
        return result;
    }

    int GetHammingDistance() const {
        return hammingDistance;
    }

    int GetHammingWeight() const {
        return hammingWeight;
    }

    bool IsExistResult() const {
        return existResult;
    }
    
    void setExistResult(bool existResult) {
        this->existResult = existResult;
    }

    void setHammingDistance( int hammingDistance) {
        this->hammingDistance = hammingDistance;
    }

    void setHammingWeight( int hammingWeight) {
        this->hammingWeight = hammingWeight;
    }

    void setResult(BinaryVector* result) {
        BinaryVector* pom=this->result;
        this->result = result;
        delete pom;
    }


private:
    BinaryVector* result;
    int hammingDistance;
    int hammingWeight;
    bool existResult;
    TaskCrate* task;

    bool* copyArray(bool* b);
};

#endif	/* RESULTCRATE_H */

