// AtCoder Beginner Contest 220
// 2021-09-26(Sun) 21:00 - 22:40, 100 minutes

// B - Base K

/* Sample Input & Output
2
1011 10100
220

7
123 456
15642
*/


#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    int K;
    string A, B;
    cin >> K >> A >> B;

    int aSize = A.size();
    int bSize = B.size();

    ll aDec = 0, bDec = 0;
    for (int i = 0; i < aSize; i++) aDec += (A[i] - '0') * pow(K, aSize - i - 1);
    for (int i = 0; i < bSize; i++) bDec += (B[i] - '0') * pow(K, bSize - i - 1);

    cout << aDec * bDec << endl;

    return 0;
}