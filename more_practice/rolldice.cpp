//rolldice
//simulates rolling die with 6 faces n times
//output gen by random num gen
//and converted to range.
//fraction of times num 6 appears is calculated.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RollDie();

int main()
{
    int outcome, N=0, count_six=0, count_other=0;
    float fraction_six, fraction_other;

    //init random num gen with value of system time
    srand(time(NULL));

    //get user input in correct range
    while(N<1 || N>1000)
    {
        cout << "Input the number of experiments (1-1000): " << endl;
        cin >> N;
    }

    //perform n experiments
    //call rolledie() n times and record num sixes
    for(int i=0; i<N; i++)
    {
        outcome = RollDie();
        cout << outcome << endl;
        if(outcome==6) 
            count_six++;
        else 
            count_other++;
    }

    //integer vars must be converted or cast for correct division
    fraction_six = static_cast<float>(count_six)/N;
    fraction_other = static_cast<float>(count_other)/N;

    //output results
    cout << "Fraction of outcomes in which 6 was rolled: "
        << fraction_six << endl;
    cout << "Fraction of outcomes in which other nums rolled: "
        <<fraction_other << endl;
    return 0;
}