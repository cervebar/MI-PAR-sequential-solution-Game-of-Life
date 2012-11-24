/* 
 * File:   TaskCrate.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 20:59
 */

#ifndef TASKCRATE_H
#define	TASKCRATE_H
#include <iostream>
#include <stdlib.h>

#include "BinaryVector.h"
using namespace std;

class TaskCrate {
public:
    TaskCrate(bool* resultingConfigurationArray,  int width,  int height,  int itrations,  int aMistake);
    TaskCrate(TaskCrate* origin);
    virtual ~TaskCrate();
    
    void printTaskCrate();
    
//GETTERS-----------------------------------------------------------------------
     int GetAMistake() const {
        return aMistake;
    }

     int GetHeight() const {
        return height;
    }

     int GetIterations() const {
        return iterations;
    }

    bool* IsResultingConfigurationArray() const {
        return resultingConfigurationArray;
    }

     int GetWidth() const {
        return width;
    }
    BinaryVector* getResultingConfigurationVector() const {
        return resultingConfigurationVector;
    }

private:
    bool* resultingConfigurationArray;
     int width;
     int height;
     int iterations;
     int aMistake;
    BinaryVector* resultingConfigurationVector;

};

#endif	/* TASKCRATE_H */

