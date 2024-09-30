// size of int is 4 bytes, address of 'myArray' is 48 in decimal, what is output
void main()
{
    int myArray[10];
    int counter;
    for(counter = 0;counter < 10; counter++)
        myArray[counter] = counter * 2;
    printf("%p, %d", (myArray+1), *(myArray+1));
}