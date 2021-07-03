// AtCoder Beginner Contest 206
// 2021-06-19(Sat) 21:00 - 22:40, 100 minutes

// C - Swappable

/* Sample input & output
3
1 7 1
2

10
1 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
45

20
7 8 1 1 4 9 9 6 8 2 4 1 1 9 5 5 5 3 6 4
173
*/

#include <iostream>
#include <vector>
#include <algorithm>    // for using sort()

using namespace std;

int main()
{
    int n;
    cin >> n;

    // input data to a vector
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // sort the vector
    sort(a.begin(), a.end());

    // count
    long long count = 0, sameNum = 1, remainedNum = (long long) n;
    for (int j = 1; j <= n-1; j++)
    {
        remainedNum--;
        if (a[j-1] == a[j])
        {
            sameNum++;
        } else
        {
            count += sameNum * remainedNum;
            sameNum = 1;
        }

        // test
        cout << j << " " << sameNum << " " << remainedNum << " " << count << endl;
    }

    // output
    cout << count << endl;

    return 0;
}