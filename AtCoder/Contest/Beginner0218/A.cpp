// AtCoder Beginner Contest 218
// 2021-09-11(Sat) 21:00 - 22:40, 100 minutes

// A - Weather Forecast

/* Sample Input & Output
4
oooxoox
No

7
ooooooo
Yes
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    if (S[N-1]=='o') cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}