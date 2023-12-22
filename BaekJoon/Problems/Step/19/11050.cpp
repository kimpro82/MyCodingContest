// 11050. 이항 계수 1
// 2023.07.12

/* Sample input & output data
5 2

10
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    // Input
    int n, k;
    cin >> n >> k;

    // Operate
    int ans = 1;
    int k2 = k;
    for (int i = 0; i < k; i++) ans *= n--;
    for (int i = 0; i < k2; i++) ans /= k--;

    // Output
    cout << ans << endl;

    return 0;
}
