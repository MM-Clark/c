void main()
{
    int myArray[10];
    int counter;
    for(counter = 0; counter < 10; counter++)
        myArray[counter] = counter * 2;
    printf("%p, %d", (myArray+8), *(myArray+8));
}