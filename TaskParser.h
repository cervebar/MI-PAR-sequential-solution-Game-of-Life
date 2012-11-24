/* 
 * File:   TaskParser.h
 * Author: Babu
 *
 * Created on 20. říjen 2012, 15:33
 */

#ifndef TASKPARSER_H
#define	TASKPARSER_H
#include "TaskParser.h"
#include "TaskCrate.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TaskParser {
public:
    TaskParser(bool verbose);
    virtual ~TaskParser();
    TaskCrate* getTaskFromFile(char* filename) ;
private:
    bool verbose;
};

#endif	/* TASKPARSER_H */

