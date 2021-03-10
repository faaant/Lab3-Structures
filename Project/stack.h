struct stack
{
    int massSize=-1;
    char *massOfElements;


    void clear()
    {
        massSize=-1;
        delete[] massOfElements;
    }


    void push(char addedElement)
    {
        massSize++;
        char *renewedMassOfElements = new char[massSize];
        for (int i=0; i<=massSize-1;i++)
            {
                 renewedMassOfElements[i]= massOfElements[i];
            }
        renewedMassOfElements[massSize]= addedElement;
        if (massSize>0)
            delete[] massOfElements;
        massOfElements=renewedMassOfElements;
    }


    char pop()
    {
        char returnedElement=massOfElements[massSize];
        massSize--;
        if(massSize!=-1)
        {
            char *renewedMassOfElements = new char[massSize];
            for (int i=0; i<=massSize;i++)
            {
                 renewedMassOfElements[i]= massOfElements[i];
            }
            delete[] massOfElements;
            massOfElements=renewedMassOfElements;

        }
        else
        {
            clear();
        }
        return returnedElement;
    }

    bool empty()
    {
        bool isEmpty;
        if (massSize==-1)
            isEmpty=true;
        else
            isEmpty=false;
        return isEmpty;
    }


    char top()
    {
        return massOfElements[massSize];
    }


};


struct stackInt
{
    int massSize=-1;
    int *massOfElements;


    void clear()
    {
        massSize=-1;
        delete[] massOfElements;
    }


    void push(int addedElement)
    {
        massSize++;
        int *renewedMassOfElements = new int[massSize];
        for (int i=0; i<=massSize-1;i++)
            {
                 renewedMassOfElements[i]= massOfElements[i];
            }
        renewedMassOfElements[massSize]= addedElement;
        if (massSize>0)
            delete[] massOfElements;
        massOfElements=renewedMassOfElements;
    }


    int pop()
    {
        int returnedElement=massOfElements[massSize];
        massSize--;
        if(massSize!=-1)
        {
            int *renewedMassOfElements = new int[massSize];
            for (int i=0; i<=massSize;i++)
            {
                 renewedMassOfElements[i]= massOfElements[i];
            }
            delete[] massOfElements;
            massOfElements=renewedMassOfElements;

        }
        else
        {
            clear();
        }
        return returnedElement;
    }


    bool empty()
    {
        bool isEmpty;
        if (massSize==-1)
            isEmpty=true;
        else
            isEmpty=false;
        return isEmpty;
    }


    int top()
    {
        return massOfElements[massSize];
    }

};
