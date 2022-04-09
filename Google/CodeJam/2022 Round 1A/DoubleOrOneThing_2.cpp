/* Sample Input & Output
3
PEEL
AAAAAAAAAA
CODEJAMDAY

Case #1: PEEEEL
Case #2: AAAAAAAAAA
Case #3: CCODDEEJAAMDAAY
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input data
        string S, newS = "";
        cin >> S;
        int len = S.length();

        // Operate
        for (int i = 0; i < len - 1; i++)
        {
            bool smaller = false;

            if (S[i] - 'A' < S[i + 1] - 'A')
            {
                // newS += S[i] + S[i];                                                 // works incorrectly
                newS += S[i];
                newS += S[i];
            }
            else if (S[i] - 'A' == S[i + 1] - 'A')                                      // leave "- 'A'" for legibility
            {
                for (int j = i; j < len - 1; j++)
                {
                    // if (j == (len - 1) - 1) smaller = false;
                    if (S[j] - 'A' == S[j + 1] - 'A') continue;
                    else if (S[j] - 'A' < S[j + 1] - 'A')
                    {
                        smaller = true;
                        break;
                    }
                    else break;                                                         // S[j] - 'A' > S[j + 1] - 'A'
                }

                if (smaller == true)
                {
                    newS += S[i];
                    newS += S[i];
                }
                else newS += S[i];
            }
            else newS += S[i];                                                          // S[j] - 'A' > S[j + 1] - 'A'

            // test
            // cout << S[i] << ' ' << S[i + 1] << ' ' << newS << ' ' << smaller << endl;
        }
        newS += S[len - 1];                                                             // The last letter doesn't need to be doubled

        // Output
        cout << "Case #" << t << ": " << newS << endl;
    }

    return 0;
}