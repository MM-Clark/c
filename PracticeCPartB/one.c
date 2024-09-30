void changeValue(int *value)
{
    *value = *value + 5;
}
void main()
{
    int var = 2;
    changeValue(&var);
    printf("%d", var);
}
// prints 7 because we passed in var's address, which was referenced and directly updated