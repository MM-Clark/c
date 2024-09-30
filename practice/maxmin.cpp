#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // cout << max(5,10);
    char nm[100];
    cin >> nm;
    ifstream fin; 
    fin.open(nm);
    cout << "Output file name = ";
    cin >> nm;

    ofstream fout;
    fout.open(nm);

    char str[1000];
    while(!fin.fail())
    {
        char str[1000];
        fin.getline(str, 1000);
        fout << str << endl;
    }
    fin.close();
    fout.close();
    return 0;
}