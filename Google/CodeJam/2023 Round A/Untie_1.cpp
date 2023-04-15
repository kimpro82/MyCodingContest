/* Sample Input & Output
3
PRSSP
RRRRRRR
RSPRPSPRS

Case #1: 2
Case #2: 4
Case #3: 0
*/


#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define test

using namespace std;

int main()
{
    // Run faster
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input N
        string C;
        cin >> C;

        // Count how many times change
        // 1) C[0] can changed
        int cnt1 = 0;
        bool justChanged = false, firstChanged = false;
        int len = C.size();
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                if (C[i] == C[len-1] || C[i] == C[i+1])
                {
                    cnt1++;
                    justChanged = true;
                    firstChanged = true;
                }
            }
            else if (i < len - 1)
            {
                if (C[i] == C[i-1] || C[i] == C[i+1])
                {
                    if (justChanged == false)
                    {
                        cnt1++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
            else
            {
                if (C[i] == C[i-1] || C[i] == C[0])
                {
                    if (justChanged == false)
                    {
                        cnt1++;
                        justChanged = true;
                    }
                    else
                    {
                        if (firstChanged == false) justChanged = false;
                    }
                }
            }
        }
        // 2) C[0] can't changed
        int cnt2 = 0;
        justChanged = false;
        for (int i = 0; i < len; i++)
        {
            if (i < len - 1)
            {
                if (C[i] == C[i-1] || C[i] == C[i+1])
                {
                    if (justChanged == false)
                    {
                        cnt2++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
            else
            {
                if (C[i] == C[i-1] || C[i] == C[0])
                {
                    if (justChanged == false)
                    {
                        cnt2++;
                        justChanged = true;
                    }
                    else
                    {
                        justChanged = false;
                    }
                }
            }
        }

        // Output
        #ifdef test
            cout << "\n<test> " << C << endl;
            cout << cnt1 << ' ' << cnt2 << endl;
        #endif
        cout << "Case #" << t << ": " << min(cnt1, cnt2) << endl;
    }

    return 0;
}

// Test Set 1: Wrong Answer