#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout.precision(10);             // for reducing error < 10^(-9)
    cout << (double)a / b << endl;

    return 0;
}