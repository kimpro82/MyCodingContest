// Educational Codeforces Round 113 (Rated for Div. 2)
// 2021.09.08 23:35, 2 hrs

// B. Chess Tournament

/* Sample Input & Output
3
3
111
2
21
4
2122

YES
X==
=X=
==X
NO
YES
X--+
+X++
+-X-
--+X

"If there are several possible outcomes, print any of them"
*/


#include <iostream>
#include <vector>

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
        cin >> n >> s;                                                  // n <= 50, no worry about time complexity

        // Case 1 : Impossible to satisfy all players' expectations
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') t1++;
            else t2++;
        }
        if (t2 > 0 && t2 <= 2)
        {
            cout << "NO" << endl;
            continue;
        }

        // Case 2 : Normal
        cout << "YES" << endl;

        vector<vector<char>> v;
        for (int i = 0; i < n; i++)
        {
            vector<char> v2;
            bool win = false;

            for (int j = 0; j < n; j++)
            {
                if (i < j)                                              // not so confident ……
                {
                    if (s[i] == '1' || s[j] == '1') v2.push_back('=');
                    else if (win == false)
                    {
                        v2.push_back('+');
                        win = true;
                    }
                    else v2.push_back('-');
                }
                else if (i == j) v2.push_back('X');
                else                                                    //  if (i > j) : must be guaranteed that v[j][i] have already existed
                {
                    if (v[j][i] == '+') v2.push_back('-');
                    else if (v[j][i] == '-')
                    {
                        v2.push_back('+');
                        win = true;
                    }
                    else v2.push_back('=');
                }

                cout << v2[j];
            }
            cout << endl;

            v.push_back(v2);
        }
    }

    return 0;
}