// Codeforces Round #790 (Div. 4)
// 2022.05.10 23:45, 2 hrs

// A. Lucky?

/* Sample Input & Output
5
213132
973894
045207
000000
055776

YES
NO
YES
YES
NO
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
        // Input data
        string ticket;
        cin >> ticket;
 
        // Solve
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < 3; j++)
        {
            sum1 += ticket[j] - '0';
            sum2 += ticket[j+3] - '0';

            // test
            // cout << sum1 << ' ' << sum2 << endl;
        }
        string ans = "Yes";
        if (sum1 != sum2) ans = "No";

        // Output
        cout << ans << endl;

    }

    return 0;
}