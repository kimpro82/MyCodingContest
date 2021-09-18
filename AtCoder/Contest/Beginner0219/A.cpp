// AtCoder Beginner Contest 219
// 2021-09-18(Sat) 21:00 - 22:40, 100 minutes

// A - AtCoder Quiz 2

/* Sample Input & Output
56
14

32
8

0
40

100
expert
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int X;
    cin >> X;

    if (X >= 90) cout << "expert" << endl;
    else if (X >= 70) cout << 90 - X << endl;
    else if (X >= 40) cout << 70 - X << endl;
    else cout << 40 - X << endl;

    return 0;
}