// AtCoder Beginner Contest 212
// 2021-07-31(Sat) 21:00 - 22:40, 100 minutes

// C - Min Difference

/* Sample Input & Output
2 2
1 6
4 9
2

1 1
10
10
0

6 8
82 76 82 82 71 70
17 39 67 2 45 35 22 24
3
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int N, M, temp;
    cin >> N >> M;
    vector<int> A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }
    for (int j = 0; j < M; j++)
    {
        cin >> temp;
        B.push_back(temp);
    }

    // Find the minimum difference
    ll min = 1000000000;
    for (int k = 0; k < N; k++)
    {
        for (int l = 0; l < M; l++)
        {
            if (abs(A[k] - B[l]) < min) min = abs(A[k] - B[l]);
            if (min == 0) break;
        }
        if (min == 0) break;
    }

    // Output
    cout << min << endl;

    return 0;
}