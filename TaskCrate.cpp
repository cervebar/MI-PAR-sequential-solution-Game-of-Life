/* 
 * File:   TaskCrate.cpp
 * Author: Babu
 * 
 * Created on 20. říjen 2012, 20:59
 */

#include "TaskCrate.h"

TaskCrate::TaskCrate(bool* resultingConfigurationArray, int width,
        int height, int iterations, int aMistake) {
    this->resultingConfigurationArray = resultingConfigurationArray;
    this->resultingConfigurationVector = new BinaryVector(resultingConfigurationArray, width, height);
    this->aMistake = aMistake;
    this->width = width;
    this->height = height;
    this->iterations = iterations;
}

TaskCrate::TaskCrate(TaskCrate* origin) {    
    this->aMistake = origin->aMistake;
    this->width = origin->width;
    this->height = origin->height;
    this->iterations = origin->iterations;
    this->resultingConfigurationArray = BinaryVector::copyArray(origin->resultingConfigurationArray, width * height);    
    this->resultingConfigurationVector = new BinaryVector(resultingConfigurationArray, width, height);
}

TaskCrate::~TaskCrate() {
    delete resultingConfigurationArray;
    delete resultingConfigurationVector;
}

void TaskCrate::printTaskCrate() {
    cout << "TASK:" << endl;
    cout << "width:" << width << ", height:" << height << ", iterations(q):" << iterations
            << ", mistake(a):" << aMistake << endl;
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << resultingConfigurationArray[index] << "|";
            index++;
        }
        cout << endl;
    }    
    //resultingConfigurationVector->printVector();
}
