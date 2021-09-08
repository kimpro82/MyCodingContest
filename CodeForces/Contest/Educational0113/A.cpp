// Educational Codeforces Round 113 (Rated for Div. 2)
// 2021.09.08 23:35, 2 hrs

// A. Balanced Substring

/* Sample Input & Output
4
1
a
6
abbaba
6
abbaba
9
babbabbaa

-1 -1
1 6
3 6
2 5

"Find any non-empty balanced substring s[l;r] of string s"
*/


#include <iostream>

using namespace std;

#define endl '\n'

int main()
{

    int t;
    cin >> t;

    // t Loops for each test case
    for (int test = 0; test < t; test++)
    {
        // Input data
        int n;
        string s;
        cin >> n >> s;                                          // n <= 50, no worry about time complexity

        // Case 1 : Impossible to make any balanced substring
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a') a++;
            else b++;
        }
        if (a == 0 || b == 0)
        {
            cout << -1 << ' ' << -1 << endl;
            continue;
        }

        // Case 2 : Normal
        int l = 0, r = 0, balance = 0;;
        for (int i = 0; i < n - 1; i++)
        {
            l = i;
            balance = 0;

            for (int j = i; j < n; j++)
            {
                r = j;
                if (s[j] == 'a') balance++;
                else balance--;

                if (balance == 0) break;

                // test
            }
            if (balance == 0) break;                            // crazy
        }
        cout << l + 1 << ' ' << r + 1 << endl;
    }

    return 0;
}