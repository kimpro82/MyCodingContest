// AtCoder Beginner Contest 213
// 2021-08-08(Sun) 21:00 - 22:40, 100 minutes

// A - Bitwise Exclusive Or

/* Sample Input & Output
3 6
5

10 12
6
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B;

    C = A ^ B;

    cout << C << endl;

    return 0;
}