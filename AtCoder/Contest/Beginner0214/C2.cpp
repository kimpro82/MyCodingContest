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

    // Operation
    vector<int> T2 = T;
    bool change = true;
    int loop = 0;
    while (change == true)
    {
        cout << "[loop : " << ++loop << " ]\n";                     // test

        cout << S[N-1] + T2[N-1] << ' ' << T2[0] << endl;           // test
        if (S[N-1] + T[N-1] < T[0]) T2[0] = S[N-1] + T2[N-1];       // when n = 0
        for (int n = 1; n < N; n++)                                 // when n > 0
        {
            // test
            cout << S[n-1] + T2[n-1] << ' ' << T2[n] << endl;

            if (S[n-1] + T2[n-1] < T2[n]) T2[n] = S[n-1] + T2[n-1];
        }

        change = false;
        for (int n = 0; n < N; n++)
        {
            if (T[n] != T2[n])
            {
                change = true;
                T = T2;
                break;
            }
        }

    }

    // Output
    for (int n = 0; n < N; n++) cout << T2[n] << endl;

    return 0;
}