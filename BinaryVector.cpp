/* 
 * File:   BinaryVector.cpp
 * Author: honza
 * 
 * Created on 7. říjen 2012, 15:54
 */

#include "BinaryVector.h"

//helping free vector - used as a nullObject

BinaryVector::BinaryVector() {
    this->actualArray = new bool[1];
    this->newArray = new bool[1];
    this->startConfiguration = new bool[1];
}

BinaryVector::BinaryVector(int width, int height) {
    this->width = width;
    this->height = height;
    this->actualArray = new bool[width * height];
    this->newArray = new bool[width * height];
    this->startConfiguration = new bool[width * height];
    this->size = width*height;
}

BinaryVector::BinaryVector(BinaryVector* orig) {
    this->width = orig->width;
    this->height = orig->height;
    this->size = orig->size;
    this->actualArray = BinaryVector::copyArray(orig->actualArray,size);
    this->newArray = BinaryVector::copyArray(orig->newArray,size);
    this->startConfiguration = BinaryVector::copyArray(orig->startConfiguration,size);
}

/**
 * Constructor that will copy the given array as a startConfiguration
 * @param array
 * @param width
 * @param height
 */
BinaryVector::BinaryVector(bool* array, int width, int height) {
    //TODO osetreni nespravneho pole, nesouhlasi vyska sirka
    this->width = width;
    this->height = height;
    this->size = width*height;
    this->startConfiguration = BinaryVector::copyArray(array,size);
    this->actualArray = BinaryVector::copyArray(array,size);
    this->newArray = new bool[width * height];

}

BinaryVector::~BinaryVector() {
    delete actualArray;
    delete newArray;
    delete startConfiguration;
}

void BinaryVector::printVector() {
    cout << "Vector width:" << width << ", height:" << height
            << ", hamWeight:" << BinaryVector::hammingStartArrayWeight(this) << endl;
    int index = 0, index2 = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << startConfiguration[index] << "|";
            index++;
        }
        cout << " => ";
        for (int j = 0; j < width; j++) {
            cout << actualArray[index2] << "|";
            index2++;
        }
        cout << endl;
    }
}

void BinaryVector::printVector2() {
    int index = 0, index2 = 0;

        for (int j = 0; j < width*height; j++) {
            cout << actualArray[index2];
            index2++;
        }
    
}

int BinaryVector::getCountOfAliveNeighbours(int index) {
    int count = 0;
    int leftMiddleIndex = index - 1;
    int leftTopIndex = index - width - 1;
    int rightTopIndex = index - width + 1;
    int rightMiddleIndex = index + 1;
    int leftBottomIndex = index + width - 1;
    int rightBottomIndex = index + width + 1;
    int topMiddleIndex = index - width;
    int bottomMiddleIndex = index + width;
    bool hasTop = true, hasBottom = true;
    //first line
    if (index - width < 0) {
        hasTop = false;
    }
    //last line
    if (index + width >= (width * height)) {
        hasBottom = false;
    }
    //has a left neigbhours
    if (index % width != 0) {
        if (hasTop) {
            count += actualArray[leftTopIndex] ? 1 : 0;
        };
        count += actualArray[leftMiddleIndex] ? 1 : 0;
        if (hasBottom) {
            count += actualArray[leftBottomIndex] ? 1 : 0;
        };
    }
    //has right neigbhours
    if ((index + 1) % width != 0) {
        if (hasTop) {
            count += actualArray[rightTopIndex] ? 1 : 0;
        };
        count += actualArray[rightMiddleIndex] ? 1 : 0;
        if (hasBottom) {
            count += actualArray[rightBottomIndex] ? 1 : 0;
        };
    }
    if (hasTop) {
        count += actualArray[topMiddleIndex] ? 1 : 0;
    }
    if (hasBottom) {
        count += actualArray[bottomMiddleIndex] ? 1 : 0;
    }
    return count;
}

void BinaryVector::writeNewValueOfCellToNextIteration(int index, int liveNeigbhours) {
    if (actualArray[index] == true) {//if is alive then stay alive with 3 or 2 neibhours
        newArray[index] = (liveNeigbhours == 2 || liveNeigbhours == 3);
    } else {//if is dead, then come back to live with 3 neigbhours
        newArray[index] = liveNeigbhours == 3;
    }
}

void BinaryVector::nextIteration() {
    for (int i = 0; i < size; i++) {
        writeNewValueOfCellToNextIteration(i, getCountOfAliveNeighbours(i));
    }
    bool* oldreference = actualArray;
    actualArray = newArray;
    newArray = oldreference;
}

void BinaryVector::iterateForQTimes(int q) {
    for (int i = 0; i < q; i++) {
        nextIteration();
    }
}

//STATIC-----------------------------------------------------------------------
bool* BinaryVector::copyArray(bool* b,int size) {
    bool* newb = new bool[size];
    for (int i = 0; i < size; i++) {
        newb[i] = b[i];
    }
    return newb;
}

void BinaryVector::printArray(bool* b,int size){
    for (int i = 0; i < size; i++) {
        cout<< b[i]<<",";
    }
}

bool* BinaryVector::getEmptyArray(int size) {
    bool* newb = new bool[size];
    for (int i = 0; i < size; i++) {
        newb[i] = false;
    }
    return newb;
}


int BinaryVector::hammingStartArrayDistance(BinaryVector* first, BinaryVector* second) {
    //TODO osetrit rozdilnost velikosti vektoru - vyhozeni vyjimky
    int distance = 0;
    for (int i = 0; i < first->getSize(); i++) {
        if (first->getStartConfiguration()[i] != second->getStartConfiguration()[i]) {
            distance++;
        }
    }
    return distance;
}

int BinaryVector::hammingStartArrayWeight(BinaryVector* vector) {
    int weight = 0;
    for (int i = 0; i < vector->getSize(); i++) {
        if (vector->getStartConfiguration()[i] == true) {
            weight++;
        }
    }
    return weight;
}

bool BinaryVector::equals(BinaryVector* first, BinaryVector* second) {
    for (int i = 0; i < first->getSize(); i++) {
        if (first->getActualArray()[i] != second->getActualArray()[i]) {
            return false;
        }
    }
    return true;
}


int BinaryVector::hammingDistance(bool* array, bool* config,int size){
    int weight = 0;
    for (int i = 0; i < size; i++) {
        if (array[i]!=config[i]) {
            weight++;
        }
    }
    return weight;
}
//test purposes****************************************************************

bool* BinaryVector::getActualArray() {
    return actualArray;
}

bool* BinaryVector::getNewArray() {
    return newArray;
}

int BinaryVector::getSize() {
    return size;
}

bool* BinaryVector::getStartConfiguration() {
    return startConfiguration;
}






