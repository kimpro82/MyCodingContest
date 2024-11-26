// AtCoder Beginner Contest 224
// 2021-10-23(Sat) 21:00 - 22:40, 100 minutes

// A - Tires

/* Sample Input & Output
atcoder
er

tourist
ist

er
er
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    string S;
    cin >> S;
    int size = S.length();

    if (S[size-1] == 'r') cout << "er" << endl;
    else cout << "ist" << endl;

    return 0;
}