/* 
 * File:   newsimpletest.cpp
 * Author: Babu
 *
 * Created on 20.11.2012, 15:40:38
 */

#include <stdlib.h>
#include <iostream>

#include "BinaryVector.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    bool* array=BinaryVector::getEmptyArray(4*8);
    
    array[0]=true;
    array[1]=true;
    array[2]=true;
    array[3]=true;
    array[4]=true;
    array[5]=true;
    array[6]=true;
    array[5]=true;
    array[7]=true;
    array[8]=true;
    array[9]=false;
    array[10]=false;
    array[11]=false;
    array[13]=false;
    array[14]=false;
    array[15]=true;
    array[16]=true;
    array[17]=true; 
    array[18]=true;
    array[19]=true;
    array[20]=true;
    array[21]=true;
    array[22]=true;
    array[23]=true;   
    
    
    BinaryVector* bv =new BinaryVector(array,4,8);
    bv->iterateForQTimes(2);
    
    bv->printVector();
    bv->printVector2();
    
    cout<<""<<endl;
    
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;
   // test2();
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

