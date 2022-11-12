// AtCoder Beginner Contest 277
// 2022-11-12(Sat) 21:00 - 22:40, 100 minutes

// A - ^{-1}

/* Sample Input & Output
4 3
2 3 1 4

5 2
3 5 1 4 2

6 6
1 2 3 4 5 6

2
5
6
*/


#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N, X;
    cin >> N >> X;
    vector<int> P;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        P.push_back(temp);
    }

    // Find X's index that starts from 1
    int idx;
    for (auto it = P.begin(); it != P.end(); it++)
    {
        if (*it == X)
        {
            idx = it - P.begin() + 1;
            break;
        }
    }

    // Output
    cout << idx << endl;

    return 0;
}