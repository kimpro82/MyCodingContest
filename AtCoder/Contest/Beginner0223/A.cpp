// AtCoder Beginner Contest 223
// 2021-10-17(Sun) 21:00 - 22:40, 100 minutes

// A - Exact Price

/* Sample Input & Output
500
Yes

40
No

0
No
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int X;
    cin >> X;

    if (X % 100 == 0 && X != 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}