#include "Shunting_yard.h"
void shuntingYard(queue<char>& output, int numOfElements, char row[])
{
    char c;
    stack operators;//<char>
    int i=0;
    while(i<numOfElements)
    {
        if ((isdigit(row[i]))||(((i==0)&&(row[i]=='-')&&(isdigit(row[i+1]))) || ((row[i-1]=='(')&&(row[i]=='-')&&(isdigit(row[i+1])))))
        {
            if((((i==0))&&(row[i]=='-')) ||((row[i]=='-')&&(row[i-1]=='(')))
            {
                c=row[i+1]+'-';
                i++;
            }
            else
                c=row[i];
            output.push(c);
        }
        else if (row[i]=='$')
        {
            c=row[i];
            operators.push(c);
        }
        else if ((row[i]=='*')||(row[i]=='/'))
        {
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
                    output.push(c);
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
            while ((!operators.empty())&&(operators.top()!='('))
            {
                c=operators.top();
                output.push(c);
                operators.pop();
            }

        }
        else if (row[i]=='(')
        {
            c=row[i];
            operators.push(c);
        }
        else if (row[i]==')')
        {
            while (operators.top()!='(')
            {
                c=operators.top();
                output.push(c);
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
            output.push(c);
            operators.pop();
        }
    }
}
