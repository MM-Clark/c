void main()
{
    char myArray[10];
    int counter;
    for(counter=0; counter<10; counter++)
        myArray[counter] = counter * 2;
    printf("%p, %d", (myArray+5), *(myArray+5));
}