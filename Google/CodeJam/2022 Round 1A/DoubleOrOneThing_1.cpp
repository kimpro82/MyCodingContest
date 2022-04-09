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
#include <vector>

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

        // Test if the case consists of only one letter.
        vector<int> v(26, 0);
        for (int i = 0; i < 26; i++) v[S[i] - 'A']++;

        // Operate
        for (int i = 0; i < len - 1; i++)
        {
            int kind = 0;
            for (int j = 0; j < 26; j++) if (v[j] > 0) kind++;               // kind; how many kinds of letters

            if (kind > 1)
            {
                if (S[i] - 'A' <= S[i + 1] - 'A')
                {
                    // newS += S[i] + S[i];                                 // works incorrectly
                    newS += S[i];
                    newS += S[i];
                }
                else newS += S[i];
            }
            else                                                            // The residual letters are only one kind
            {
                for (int k = i; k < len - 1; k++) newS += S[k];
                break;
            }

            // test
            cout << S[i] << ' ' << S[i + 1] << ' ' << newS << ' '  << kind << endl;

            v[S[i] - 'A']--;
        }
        newS += S[len - 1];                                                 // The last letter doesn't need to be doubled

        // Output
        cout << "Case #" << t << ": " << newS << endl;
    }

    return 0;
}