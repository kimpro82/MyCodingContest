// 1010. 다리 놓기
// 2023.07.12

/* Sample input & output data
3
2 2
1 5
13 29

1
5
67863915
*/


#include <iostream>

#define endl '\n'

using namespace std;


int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input
        int n, m;
        cin >> n >> m;

        // Operate : mCn
        long long ans = 1;
        for (int j = 1; j <= n; j++)                        // j must start from 1, not 0
        {
            ans *= m--;
            ans /= j;
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}
