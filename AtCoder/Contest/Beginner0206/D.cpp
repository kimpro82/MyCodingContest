// AtCoder Beginner Contest 206
// 2021-06-19(Sat) 21:00 - 22:40, 100 minutes

// D - KAIBUNsyo

/* Sample input & output
8
1 5 3 2 5 2 3 1
2

7
1 2 3 4 1 2 3
1

1
200000
0
*/

#include <iostream>
#include <set>

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

    set<int> numToChange;
    for (int i = 1; i <= (n+1)/2; i++)
    {
        if (a[i-1] != a[n-i])
        {
            numToChange.insert(a[i-1]);
            numToChange.insert(a[n-i]); 
            cout << i-1 << " " << a[i-1] << " " << n-i << " " << a[n-i]
                << " " << numToChange.size() << endl;                   // test 
        }
    }
    if (numToChange.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << numToChange.size()-1 << endl;
    }

    return 0;
}