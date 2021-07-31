// Codeforces Round #734 (Div. 3)
// 2021.07.23 23:35, 2 hrs

// A. Polycarp and Coins

/* Sample Input & Output
6
1000
30
1
32
1000000000
5

334 333
10 10
1 0
10 11
333333334 333333333
1 2
*/


#include <iostream>

using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        int n;
        cin >> n;

        // Count
        int a, b;
        b = (n + 1)/3;
        a = n - b*2;

        // Output
        cout << a << ' ' << b << endl;
    }

    return 0;
}