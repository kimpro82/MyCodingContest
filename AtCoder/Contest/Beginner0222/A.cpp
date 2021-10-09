// AtCoder Beginner Contest 222
// 2021-10-09(Sat) 21:00 - 22:40, 100 minutes

// A - Four Digits

/* Sample Input & Output
321
0321

7777
7777

1
0001
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    string N;
    cin >> N;
    int zero = 4 - N.length();

    for (int i = 0; i < zero; i++) cout << '0';
    cout << N << endl;

    return 0;
}