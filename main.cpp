/* 
 * File:   main.cpp
 * Author: honza
 *
 * Created on 7. říjen 2012, 15:41
 */

#include <iostream>

#include "BinaryVector.h"
#include "Worker.h"
#include "TaskParser.h"
#include <math.h>
#include <time.h>
#include "ParentNode.h"
#include "Node.h"
#include "LeafNode.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    clock_t t1,t2;
    
    TaskParser* parser = new TaskParser(true);
    TaskCrate* taskCrate = parser->getTaskFromFile("testTasks/test553.txt");
    //TaskCrate* taskCrate = parser->getTaskFromFile("testTasks/test55.txt");           

    int size = (taskCrate->GetHeight())* (taskCrate->GetWidth());
    bool* initialArray = new bool[size];
    for (int i = 0; i < size; i++) {
        initialArray[i] = false;
    }
    Worker* worker = new Worker(taskCrate, initialArray, NULL, false);
    
    t1=clock();
    
    worker->work();
    ResultCrate* result = worker->getResult();
    
    t2=clock();
    
    result->printResult();
    ResultCrate* mistakeresult = worker->getSmallMistakeResult();
    mistakeresult->printResult();
    
    float diff = ((float)t2-(float)t1);
    printf ("Spotrebovany cas je %f.\n",diff);

    delete mistakeresult;
    delete result;
    delete worker;
    delete parser;
    return 0;
}
