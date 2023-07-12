// 13241. LCM(최소공배수)
// 2023.07.09

/* Sample input & output data
121 199

24079
*/


#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input
    ll a, b, Max, Min, prod, ans;
    cin >> a >> b;
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

    return 0;
}
