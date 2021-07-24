// AtCoder Beginner Contest 210
// 2021-07-17(Sat) 21:00 - 22:40, 100 minutes

// C - Colorful Candies

/* Sample Input & Output
7 3
1 2 1 2 3 3 1
3

5 5
4 4 4 4 4
1
*/


#pragma GCC optimize ("O2")
#pragma GCC target ("avx")

#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Input data
    int n, k;
    cin >> n >> k;
    vector<int> c;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        c.push_back(temp);
    }

    // Find the max number of colors in vector c's subsets of length k
    set<int> s;
    int max = 0, sSize;
    int index;                                          // test
    for (int j = 0; j < n - k + 1; j++)
    {
        s = {};
        for (int l = j; l < j + k; l++) s.insert(c[l]);
        sSize = s.size();
        if (sSize == k)
        {
            max = sSize;
            index = j;                                  // test
            break;
        } else if (sSize > max)
        {
            max = sSize;
            index = j;                                  // test
        }
    }

    // Output
    cout << max << endl;

    // test
    for (int m = index; m < index + max; m++)
    {
        cout << c[m] << " ";
    }
    cout << endl;

    return 0;
}