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

    vector<int> a;                  // a : ID number
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    // Allocation 1 : When sweets are more than n
    ll base = k / n;
    vector<ll> allocation (n, base);

    // Allocation 2 : When allocate sweets to citizens from the smaller ID number
    // 2-1 : Rank ID numbers from smaller
    vector<int> rank (n, 1);
    for (int j = 0; j < n; j++)
    {
        for (int l = 0; l < n; l++)
        {
            if (a[j] > a[l]) rank[j]++;
        }
    }
    // 2-2 : Give one candy more to the higher ranker (<= k & n)
    int residual = k % n; 
    for (int m = 0; m < n; m++)
    {
        if (rank[m] <= residual) allocation[m]++;
    }

    // Output
    for (int o = 0; o < n; o++) cout << allocation[o] << endl;

    return 0;
}