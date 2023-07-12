// 1934. 최소공배수
// 2023.07.09

/* Sample input & output data
3
1 45000
6 10
13 17

45000
30
221
*/


#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;


int main()
{
    // Input
    int t;
    cin >> t;

    int a, b, Max, Min, prod, ans;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;                                      // a, b <= 45,000 → a * b < 2.1b
        Max = max(a, b);
        Min = min(a, b);
        prod = a * b;
        ans = Max;

        // Operate
        while (ans < prod)
        {
            if (ans % Min == 0) break;
            ans += Max;
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}
