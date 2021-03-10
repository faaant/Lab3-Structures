#include "Prints.h"

void printQ(queue<char>& Q)
{
    queue<char> q = Q;
    while (!q.empty())
    {
        cout <<q.front()<<" ";
        q.pop();
    }
    cout <<endl;
}
