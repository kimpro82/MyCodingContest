#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;                  // 1 3
    cout.precision(10);             // for reducing error < 10^(-9)
    cout << (double)a / b << endl;

    return 0;
}