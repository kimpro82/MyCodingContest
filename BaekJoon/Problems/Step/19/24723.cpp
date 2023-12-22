// 24723. 녹색거탑
// 2023.07.12

/* Sample input & output data
2

4
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    // Input
    int n;
    cin >> n;

    // Operate
    int ans = 1;
    while (n--) ans *= 2;

    // Output
    cout << ans << endl;

    return 0;
}
