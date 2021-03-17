#include "Calculator.h"
#include "stack.h"
#include "Prints.h"
void calculate(string outputQ)
{
    string output = outputQ;
    stackDouble saver;
    int result=0;
    int i=0,
        i1=0;
    while (i<output.length())
    {

        if(isdigit(output[i]))
        {

            i1=i;
            while(isdigit(output[i])) i++;
            if(output[i]=='.')
            {
                i++;
                while (isdigit(output[i])) i++;
            }
            saver.push(stof(output.substr(i1,i-i1)));

        }
        else if((output[i]=='-') && (isdigit(output[i+1])))
        {
            i1=i;
            i++;
            while(isdigit(output[i])) i++;
            if(output[i]=='.')
            {
                i++;
                while (isdigit(output[i])) i++;
            }
            saver.push(stof(output.substr(i1,i-i1)));
        }

        while ((!isspace(output[i]))&&(!output.empty()))
        {
            if (output[i]=='+')
            {
                double sum =saver.pop()+ saver.pop();
                saver.push(sum);
                i++;
            }
            else if (output[i]=='*')
            {
                double mult = saver.pop()*saver.pop();
                saver.push(mult);
                i++;
            }
            else if (output[i]=='/')
            {
                double num= saver.pop();
                double division = saver.pop() / num;
                saver.push(division);
                i++;
            }
            else if (output[i]=='-')
            {
                double num=saver.pop();
                double substraction =saver.pop()-num;
                saver.push(substraction);
                i++;
            }
            else if (output[i]=='$')
            {
                int degreeOfNumber=1;
                double elements[degreeOfNumber];
                i++;
                while(output[i]=='$')
                {
                    i++;
                    degreeOfNumber++;
                }
                for(int j=0; j<=degreeOfNumber;j++)
                {
                    elements[j]=saver.pop();
                }
                for(int j=1; j<=degreeOfNumber;j++)
                {
                    elements[j]= pow(elements[j],elements[j-1]);
                }
                saver.push(elements[degreeOfNumber]);
            }
        }
        i++;
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

