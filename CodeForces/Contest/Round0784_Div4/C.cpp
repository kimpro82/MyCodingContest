// Codeforces Round #784 (Div. 4)
// 2022.04.21 23:35, 2 hrs

// C. Odd/Even Increments

/* Sample Input & Output
4
3
1 2 1
4
2 2 2 3
4
2 2 2 2
5
1000 1 1000 1 1000

YES
NO
YES
YES
*/


#include <iostream>
#include <vector>

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

        vector<int> a = {0};
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            a.push_back(temp);
        }

        // Solve
        int odd = a[1] % 2;
        int even = a[2] % 2;
        string ans = "YES";
        for (int j = 1; j <= n; j++)
        {
            // test
            // cout << a[j] << ' ';

            if (j % 2 == 1)
            {
                if (a[j] % 2 != odd)
                {
                    ans = "NO";
                    break;
                }
            }
            else
            {
                if (a[j] % 2 != even)
                {
                    ans = "NO";
                    break;
                }
            }
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}