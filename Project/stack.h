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




};
