// AtCoder Beginner Contest 212
// 2021-07-31(Sat) 21:00 - 22:40, 100 minutes

// A - Alloy

/* Sample Input & Output
50 50
Alloy

100 0
Gold

0 100
Silver

100 2
Alloy
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    if (A != 0 && B == 0) cout << "Gold" << endl;
    else if (A == 0) cout << "Silver" << endl;
    else cout << "Alloy" << endl;

    return 0;
}