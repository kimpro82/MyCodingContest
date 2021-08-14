// AtCoder Beginner Contest 214
// 2021-08-14(Sat) 21:00 - 22:40, 100 minutes

// C - Distribution

/* Sample Input & Output
3
4 1 5
3 10 100

3
7
8

4
100 100 100 100
1 1 1 1

1
1
1
1

4
1 2 3 4
1 2 4 7

1
2
4
7

8
84 87 78 16 94 36 87 93
50 22 63 28 91 60 64 27

50
22
63
28
44
60
64
27
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data : N
    int N, temp;
    cin >> N;

    // Input data : vector S, T
    vector<int> S, T;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        S.push_back(temp);
    }
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        T.push_back(temp);
    }

    // Output
    cout << S[N-1] + T[N-1] << ' ' << T[0] << ' ';  // test
    T[0] = min(S[N-1] + T[N-1], T[0]);              // when n = 0
    cout << T[0] << endl;
    for (int n = 1; n < N; n++)                     // when n > 0
    {
        // test
        cout << S[n-1] + T[n-1] << ' ' << T[n] << ' ';

        T[n] = min(S[n-1] + T[n-1], T[n]);
        cout << T[n] << endl;
    }

    return 0;
}