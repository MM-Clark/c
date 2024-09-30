// ScalarProduct
// Calculate scalar product btwn vectors
#include <iostream>
using namespace std;

int main()
{
    float vectorA[3], vectorB[3], scalar=0.0;
    int i;

    //get input vectors from user
    cout << "Enter elements of first vector: " << endl;
    for(i=0;i<3;i++)
    {
        cin >> vectorA[i];
    }
    cout << "Enter elements of second vector: " << endl;
    for(i=0;i<3;i++)
    {
        cin >> vectorB[i];
    }

    //calc scalar product
    for(i=0;i<3;i++)
    {
        scalar = scalar + (vectorA[i] * vectorB[i]);
    }

    //output result
    cout << "Scalar product is " << scalar << endl;
    return 0;
}