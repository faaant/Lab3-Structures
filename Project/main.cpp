#include <iostream>
#include <string>
//#include "stack.h"
#include <queue>
#include "Prints.h"
#include "divideToChars.h"
#include "Calculator.h"
#include "Shunting_yard.h"
using namespace std;

int main(int argc, char* argv[])
{

 //   queue<char> output;
    string output="";
    char row[argc*1000];
    int numOfElements=0;
    divideToChars(argc,argv,numOfElements,row);
    shuntingYard(output,numOfElements,row);
    cout<< output <<endl;
    calculate(output);
//    while (!output.empty())
//        output.pop();
    return 0;
}
