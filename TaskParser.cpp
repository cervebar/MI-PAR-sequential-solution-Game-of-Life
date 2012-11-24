/* 
 * File:   TaskParser.cpp
 * Author: Babu
 * 
 * Created on 20. Ĺ™Ă­jen 2012, 15:33
 */

#include "TaskParser.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

TaskParser::TaskParser(bool verbose) {
    this->verbose = verbose;
}

TaskParser::~TaskParser() {
}

TaskCrate* TaskParser::getTaskFromFile(char* filename) {
    bool* config;
     int widthInt;
     int heightInt;
     int amistakeInt;
     int iterationsInt;
     int configItem;

    string line;
    ifstream myfile(filename);
    size_t found;
    int strLineLength;
    int strLength;
    string temp;
    string tempStartConfiguration;

    string width("width=");
    string height("height=");
    string start_configuration("start configuration=");
    string iterations("iterations=");
    string a_mistake("a-mistake=");

    if (myfile) // same as: if (myfile.good())
    {
        while (getline(myfile, line)) // same as: while (getline( myfile, line ).good())
        {
            // different member versions of find in the same order as above:
            found = line.find(width);
            if (found != string::npos) {
                strLineLength = line.length(); //line length
                strLength = width.length(); //string length
                temp = line.substr(strLength, strLineLength - strLength);
                istringstream is(temp);
                is >> widthInt;
                is.clear();                
            }
            found = line.find(height);
            if (found != string::npos) {
                strLineLength = line.length(); //line length
                strLength = height.length(); //string length
                temp = line.substr(strLength, strLineLength - strLength);
                istringstream is(temp);
                is >> heightInt;
                is.clear();
            }
            found = line.find(start_configuration);
            if (found != string::npos) {
                strLineLength = line.length(); //line length
                
                strLength = start_configuration.length(); //string length
                
                tempStartConfiguration = line.substr(strLength, strLineLength - strLength);
                
            }
            found = line.find(iterations);
            if (found != string::npos) {
                strLineLength = line.length(); //line length
                strLength = iterations.length(); //string length
                temp = line.substr(strLength, strLineLength - 1);
                istringstream is(temp);
                is >> iterationsInt;
                is.clear();
            }
            found = line.find(a_mistake);
            if (found != string::npos) {
                strLineLength = line.length(); //line length
                strLength = a_mistake.length(); //string length
                temp = line.substr(strLength, strLineLength - strLength);
                istringstream is(temp);
                is >> amistakeInt;
                is.clear();
            }
        }
        
        config = new bool[widthInt * heightInt];
        for (int i = 0; i < (widthInt*heightInt); i++) {
            temp = tempStartConfiguration.substr(i, 1);
            //  cout << "temp " << i+1 << ": " << temp;
            istringstream is(temp);
            is >> configItem;
            if (configItem == 0) {
                config[i] = false;
            }
            if (configItem == 1) {
                config[i] = true;
            }
            is.clear();
        }

        myfile.close();
    } else cout << "Unable to open file\n";

    if (verbose) {
        cout << "loaded width: " << widthInt << endl;
        cout << "loaded height: " << heightInt << endl;
        cout << "loaded iterations: " << iterationsInt << endl;
        cout << "loaded a-mistake: " << amistakeInt << endl;
        int j = 0;
        cout << "configuration: ";       
        
        for (int i = 0; i < (widthInt*heightInt); i++) {
            cout << config[i] << " ";
//            if (config[i] == true) {
//                cout << "pravda" << endl;
//            } else if (config[i] == false) {
//                cout << "nepravda" << endl;
//            } else cout << "nevim" << endl;
        }
        cout <<endl<< "-----------------------------------------------------" << endl;
    }
    return new TaskCrate(config, widthInt, heightInt, iterationsInt, amistakeInt);
}

