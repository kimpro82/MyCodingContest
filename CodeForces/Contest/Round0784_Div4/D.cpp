// Codeforces Round #784 (Div. 4)
// 2022.04.21 23:35, 2 hrs

// D. Colorful Stamp

/* Sample Input & Output
12
5
BRBBW
1
B
2
WB
2
RW
3
BRB
3
RBB
7
WWWWWWW
9
RBWBWRRBW
10
BRBRBRBRRB
12
BBBRWWRRRWBR
10
BRBRBRBRBW
5
RBWBW

YES
NO
NO
NO
YES
YES
YES
NO
YES
NO
YES
NO
*/


#include <iostream>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Solve
        string ans = "YES";
        pair<int, int> rb(0, 0);
        int continuous = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'W')
            {
                if (continuous == 1 || (continuous > 1 && min(rb.first, rb.second) == 0))
                {
                    ans = "NO";
                    break;
                }
                continuous = 0;
                rb.first = 0;
                rb.second = 0;
            }
            else // s[j] == 'R' || s[j] == 'B'
            {
                if (s[j] == 'R') rb.first++;
                else rb.second++;

                continuous++;
            }
        }
        if (continuous == 1) ans = "NO";

        // Output
        cout << ans << endl;
    }

    return 0;
}