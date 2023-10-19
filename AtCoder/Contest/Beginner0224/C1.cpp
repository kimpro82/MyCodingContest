// AtCoder Beginner Contest 224
// 2021-10-23(Sat) 21:00 - 22:40, 100 minutes

// C - Triangle?

/* Sample Input & Output
4
0 1
1 3
1 1
-1 -1

3

20
224 433
987654321 987654321
2 0
6 4
314159265 358979323
0 0
-123456789 123456789
-1000000000 1000000000
124 233
9 -6
-4 0
9 5
-7 3
333333333 -333333333
-9 -1
7 -10
-1 5
324 633
1000000000 -1000000000
20 0

1124
*/


#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<double> X, Y;
    double x, y;
    for (int n = 0; n < N; n++)
    {
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }

    double gradient;
    int count = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            if (Y[i] - Y[j] != 0) gradient = (X[i] - X[j]) / (Y[i] - Y[j]);
            else gradient = abs((X[i] - X[j]) / (Y[i] - Y[j]));

            for (int k = j + 1; k < N; k++)
            {
                if ((X[k] - X[i]) / (Y[k] - Y[i]) == gradient) break;
                count++;                                                // not a broken case

                // test
                cout << i << ' ' << j << ' ' << k << ' ' << gradient << ' ' << count << endl;
            }
        }
    }

    cout << count << endl;

    return 0;
}