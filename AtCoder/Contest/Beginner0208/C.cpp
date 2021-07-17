// AtCoder Beginner Contest 208
// 2021-07-04(Sun) 21:00 - 22:40, 100 minutes

// C - Fair Candy Distribution

/* Sample Input & Output
2 7
1 8
4
3

1 3
33
3

7 1000000000000
99 8 2 4 43 5 3
142857142857
142857142857
142857142858
142857142857
142857142857
142857142857
142857142857
*/


#include <iostream>
#include <vector>
#include <algorithm>    // for sort()

#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int n;
    ll k;
    cin >> n >> k;

    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    // When sweets are more than n
    ll base = k / n;
    vector<ll> allocation (n, base);

    // When allocate sweets from citizens with the smaller ID number


    // Output
    for (int l = 0; l < n; l++)
    {
        cout << allocation[l] << endl;
    }

    return 0;
}