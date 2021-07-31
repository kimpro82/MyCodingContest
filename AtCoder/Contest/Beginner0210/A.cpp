// AtCoder Beginner Contest 210
// 2021-07-17(Sat) 21:00 - 22:40, 100 minutes

// A - Cabbages

/* Sample Input & Output
5 3 20 15
90

10 10 100 1
1000
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int n, a, x, y, sum;
    cin >> n >> a >> x >> y;

    if (n > a) sum = a * x + (n - a) * y;
    else sum = n * x;

    cout << sum << endl;

    return 0;
}