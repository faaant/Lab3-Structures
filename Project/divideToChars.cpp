#include "divideToChars.h"
void divideToChars(int numElInp, char* input[], int& j, char* newMas)
{
    for (int i=1; i<numElInp;i++)
    {
        if (input[i][1])
        {
            int k=1;
            while (input[i][k])
            {
                newMas[j]=input[i][k-1];
                j++;
                k++;
            }
            newMas[j]=input[i][k-1];
            j++;
        }
        else
        {
            newMas[j]=input[i][0];
            j++;
        }
    }
}
