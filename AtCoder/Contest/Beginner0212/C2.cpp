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
#include <set>      // instead of <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N, M, temp;
    cin >> N >> M;
    set<int> A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.insert(temp);
    }
    int aSize = A.size();
    for (int j = 0; j < M; j++)
    {
        cin >> temp;
        B.insert(temp);
    }
    int bSize = B.size();

    // Find the minimum difference
    int min = 1000000000, diff;
    for (auto it1 = A.begin(); it1 != A.end(); it1++)
    {
        for (auto it2 = B.begin(); it2 != B.end(); it2++)
        {
            diff = abs(*it1 - *it2);
            if (diff < min) min = diff;

            // test
            cout << *it1 << ' ' << *it2 << ' ' << diff << ' ' << min << ' ' << endl;

            if (diff < min) min = diff;
            if (min == 0 || diff > min) break;
        }
        if (min == 0) break;
    }

    // Output
    cout << min << endl;

    return 0;
}