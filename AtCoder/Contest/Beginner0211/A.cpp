// AtCoder Beginner Contest 211
// 2021-07-24(Satn) 21:00 - 22:40, 100 minutes

// A - Blood Pressure

/* Sample Input & Output
130 100
110

300 50
133.3333333

123 123
123
*/


#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout.precision(10);
    cout << (double) (a - b)/3 + b << endl;

    return 0;
}