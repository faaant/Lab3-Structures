#include "Calculator.h"
#include "stack.h"
#include "Prints.h"
void calculate(queue<char>& outputQ)
{
    queue<char> output = outputQ;
    stackInt saver;
    int result=0;
    int stop;
    while (!output.empty())
    {
        while (((isdigit(output.front()))&&(!output.empty()))||((isdigit(output.front()-'-'))&&(!output.empty())))
        {
            if(isdigit(output.front()))
                saver.push(charToInt(output.front()));
            else if(isdigit(output.front()-'-'))
            {
                 int num=(charToInt(output.front()-'-'))*(-1);
                 saver.push(num);
            }
            if (!output.empty()) output.pop();
            printQ(output);
        }

        while ((!isdigit(output.front()))&&(!output.empty())&&(!isdigit(output.front()-'-')))
        {
            if (output.front()=='+')
            {
                int sum =saver.pop()+ saver.pop();
                saver.push(sum);
                output.pop();
            }
            else if (output.front()=='*')
            {
                int mult = saver.pop()*saver.pop();
                saver.push(mult);
                output.pop();
            }
            else if (output.front()=='/')
            {
                int num= saver.pop();
                int division = saver.pop() / num;
                saver.push(division);
                output.pop();
            }
            else if (output.front()=='-')
            {
                int num=saver.pop();
                int substraction =saver.pop()-num;
                saver.push(substraction);
                output.pop();
            }
            else if (output.front()=='$')
            {
                int degreeOfNumber=1;
                int elements[degreeOfNumber];
                output.pop();
                while(output.front()=='$')
                {
                    output.pop();
                    degreeOfNumber++;
                }
                cout<< degreeOfNumber<<endl<<endl;
                for(int i=0; i<=degreeOfNumber;i++)
                {
                    elements[i]=saver.pop();
                }
                for(int i=1; i<=degreeOfNumber;i++)
                {
                    elements[i]= pow(elements[i],elements[i-1]);
                }
                saver.push(elements[degreeOfNumber]);
            }


    }
    if(!saver.empty()) cout<<endl<<saver.pop();
}

int charToInt (char num)
{
    char c='0';
    for (int i = 0; i<10;i++)
    {
        if (c+i==num)
            return i;
    }
}


