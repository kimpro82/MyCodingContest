// AtCoder Beginner Contest 215
// 2021-08-21(Sat) 21:00 - 22:40, 100 minutes

// A - Your First Judge

/* Sample Input & Output
Hello,World!
AC

Hello,world!
WA

Hello!World!
WA
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    string S;   // S doesn't have space
    cin >> S;

    string ans;
    if (S == "Hello,World!") ans = "AC";
    else ans = "WA";

    cout << ans << endl;

    return 0;
}