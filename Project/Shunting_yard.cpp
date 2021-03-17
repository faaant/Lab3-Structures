#include "Shunting_yard.h"
void shuntingYard(string& output,int numOfElements, char row[])//queue<char>& output,
{
    char c;
    stack operators;//<char>
    int i=0;
    while(i<numOfElements)
    {
        if (isdigit(row[i]))
        {
            c=row[i];
            output=output+c;
        }
        else if (((i==0)&&(row[i]=='-')&&(isdigit(row[i+1]))) || ((row[i-1]=='(')&&(row[i]=='-')&&(isdigit(row[i+1]))))
        {
            output=output+row[i]+row[i+1];
            i++;
        }
        else if (row[i]=='.')
        {
            c=row[i];
            output=output+c;
        }
        else if (row[i]=='$')
        {
            output=output+" ";
            c=row[i];
            operators.push(c);
        }
        else if ((row[i]=='*')||(row[i]=='/'))
        {
            output=output+" ";
            if (operators.empty())
            {
                c=row[i];
                operators.push(c);
            }
            else
            {
                if ((operators.top()=='$')||(operators.top()=='*')||(operators.top()=='/'))
                {
                    c=operators.top();
                    output=output+" "+c+" ";
                    operators.pop();
                    c=row[i];
                    operators.push(c);
                }
                else
                {
                    c=row[i];
                    operators.push(c);
                }
            }
        }
        else if ((row[i]=='+')||(row[i]=='-'))
        {
            output=output+" ";
            while ((!operators.empty())&&(operators.top()!='('))
            {
                c=operators.top();
                output=output+" "+c+" ";
                operators.pop();
            }
            c=row[i];
            operators.push(c);
        }
        else if (row[i]=='(')
        {
            c=row[i];
            operators.push(c);
        }
        else if (row[i]==')')
        {
            output=output;
            while (operators.top()!='(')
            {
                c=operators.top();
                output=output+" "+c+" ";
                operators.pop();
            }
            if (operators.top()=='(')
            {
                operators.pop();
            }
        }
        i++;

    }
    if (!operators.empty())
    {
        while (!operators.empty())
        {
            c=operators.top();
            output=output+" "+c+" ";
            operators.pop();
        }
    }
}
