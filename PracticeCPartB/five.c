void changeValue(int *value)
{
    value = value + 5;
}
void main()
{
    int var = 7;
    changeValue(*var);
    printf("%d", var);
}