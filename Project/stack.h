struct stack
{
    int massSize=-1;
    char *massOfElements=(char *) malloc(1*sizeof(char));


    void clear()
    {
        massSize=-1;
        free(massOfElements);
        char *massOfElements=(char *) malloc(1*sizeof(char));
    }


    void push(char addedElement)
    {
        massSize++;
        realloc(massOfElements,massSize+1);
        massOfElements[massSize] = addedElement;
    }


    char pop()
    {
        char returnedElement=massOfElements[massSize];
        massSize--;
        if(massSize!=-1)
        {
            realloc(massOfElements,massSize+1);
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
    int *massOfElements=(int *) malloc(1*sizeof(int));


    void clear()
    {
        massSize=-1;
        free(massOfElements);
        int *massOfElements=(int *) malloc(1*sizeof(int));
    }


    void push(int addedElement)
    {
        massSize++;
        realloc(massOfElements,massSize+1);
        massOfElements[massSize] = addedElement;
    }


    int pop()
    {
        int returnedElement;
        if (massSize!=-1) {returnedElement=massOfElements[massSize];}
        else returnedElement=0;
        massSize--;
        if(massSize!=-1)
        {
            realloc(massOfElements,massSize+1);
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

struct stackDouble
{
    int massSize=-1;
    double *massOfElements=(double *) malloc(1*sizeof(double));


    void clear()
    {
        massSize=-1;
        free(massOfElements);
        double *massOfElements=(double *) malloc(1*sizeof(double));
    }


    void push(double addedElement)
    {
        massSize++;
        realloc(massOfElements,massSize+1);
        massOfElements[massSize] = addedElement;
    }


    double pop()
    {
        double returnedElement;
        if (massSize!=-1) {returnedElement=massOfElements[massSize];}
        else returnedElement=0;
        massSize--;
        if(massSize!=-1)
        {
            realloc(massOfElements,massSize+1);
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


    double top()
    {
        return massOfElements[massSize];
    }

};
