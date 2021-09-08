// Educational Codeforces Round 112 (Rated for Div. 2)
// 2021.07.30 23:35, 2 hrs

// A. PizzaForces

/* Sample Input & Output
6
12
15
300
1
9999999999999999
3

30
40
750
15
25000000000000000
15
*/


#include <iostream>

using namespace std;

using ll = long long;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        // Input data
        ll n;
        cin >> n;
 
        // Calculate minimum time
        ll s10, time = 0;
        if (n < 20) s10 = 0;
        else {
            s10 = (n / 10) - 1;
            time += s10 * 25;
        }
        ll res = n - (10 * s10);
        if (res <= 6) time += 15;
        else if (res <= 8) time += 20;
        else if (res <= 10) time += 25;
        else if (res <= 12) time += 30;
        else if (res <= 14) time += 35;
        else if (res <= 16) time += 40;
        else if (res <= 18) time += 45;
        else time += 50;

        // Output
        cout << time << endl;

    } // The end of t loop

    return 0;
}