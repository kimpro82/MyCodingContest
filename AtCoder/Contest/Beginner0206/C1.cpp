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

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int k = 0; k < n; k++)
    {
        cin >> a[k];
    }

    long long count = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (a[i-1] != a[j-1])
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}