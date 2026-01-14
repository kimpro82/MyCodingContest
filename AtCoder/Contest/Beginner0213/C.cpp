// AtCoder Beginner Contest 213
// 2021-08-08(Sun) 21:00 - 22:40, 100 minutes

// C - Reorder Cards

/* Sample Input & Output
4 5 2
3 2
2 5

2 1
1 2

1000000000 1000000000 10
1 1
10 10
100 100
1000 1000
10000 10000
100000 100000
1000000 1000000
10000000 10000000
100000000 100000000
1000000000 1000000000

1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int H, W, N;
    cin >> H >> W >> N;

    int temp1, temp2;
    vector<vector<int>> v = {vector<int> {0, 0}};
    for (int n = 0; n < N; n++)
    {
        cin >> temp1 >> temp2;
        v.push_back(vector<int> {temp1, temp2});
    }

    // test
    for (int n = 0; n <= N; n++)cout << v[n][0] << ' ' << v[n][1] << endl;

    // Get rank and output
    int rank1, rank2, max1, max2;
    for (int i = 1; i <= N; i++)
    {
        rank1 = 1;
        rank2 = 1;
        max1 = 0;
        max2 = 0;

        for (int j = 1; j <= N; j++)
        {
            if (v[j][0] > max1)
            {
                max1 = v[j][0];
                rank1++;
            }
            if (v[j][1] > max2)
            {
                max2 = v[j][1];
                rank2++;
            }
        }

        cout << rank1 << ' ' << rank2 << endl;
    }

    return 0;
}