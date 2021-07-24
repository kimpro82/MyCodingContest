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
#include <map>
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
    map<int, int> m;
    int max = 0, mSize = 0;
    int index = n;                  // test
    for (int j = 0; j < n; j++)
    {
        // remove the oldest element
        if (j >= k - 1)
        {
            if (m.find(c[j-k])->second > 1) m.find(c[j-k])->second--;
            else m.erase(c[j-k]);
        }

        // insert a new element
        if (m.find(c[j]) == m.end()) m.insert(pair<int, int> (c[j], 1));
        else m.find(c[j])->second++;

        // test
        for (auto it = m.begin(); it != m.end(); it++) cout << it->first << ' ';
        cout << endl;

        // judge if max
        mSize = m.size();
        if (mSize == k)
        {
            max = mSize;
            index = j;              // test
            break;
        } else if (mSize >= max)
        {
            max = mSize;
            index = j;              // test
        }
    }

    // Output
    cout << max << endl;

    // test
    for (int l = index - k + 1; l < index + 1; l++) cout << c[l] << " ";
    cout << endl;

    return 0;
}