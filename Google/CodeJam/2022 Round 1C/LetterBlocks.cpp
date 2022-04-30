/* Sample Input & Output
6
5
CODE JAM MIC EEL ZZZZZ
6
CODE JAM MIC EEL ZZZZZ EEK
2
OY YO
2
HASH CODE
6
A AA BB A BA BB
2
CAT TAX

Case #1: ZZZZZJAMMICCODEEEL
Case #2: IMPOSSIBLE
Case #3: IMPOSSIBLE
Case #4: IMPOSSIBLE
Case #5: BBBBBAAAAA
Case #6: IMPOSSIBLE
*/


#include <iostream>
#include <array>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Run faster
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    // Each test case
    for (int t = 1; t <= T; t++)
    {
        // Input data
        int N;
        cin >> N;

        vector<string> S;
        string s;
        for (int n = 0; n < N; n++)
        {
            cin >> s;
            S.push_back(s);
        }

        // Test validation
        vector<vector<int>> v2 (4, vector<int> (26, 0));                                                    // start, middle, end, entire for each alphabet

        // 1. Test validaton
        vector<vector<int>> v1 (4, vector<int> (26, 0));
        bool possible = true;
        for (int n = 0; n < N; n++)
        {
            int continuous = true;
            int len = S[n].size();

            // 1.1 Find if the word consist only of one alphabet
            for (int i = 1; i < len; i++)
            {
                if (S[n][i] != S[n][i-1])
                {
                    continuous = false;
                    break;
                }
            }

            // 1.2 Test validaton in a word
            if (continuous == true) v2[3][S[n][0] - 'A']++;
            else
            {
                for (int i = 0; i < len; i++)
                {
                    if (i == 0) v1[0][S[n][i] - 'A']++;
                    else if (i < len-1 && S[n][i] != S[n][i-1]) v1[1][S[n][i] - 'A']++;
                    else v1[2][S[n][i] - 'A']++;                                                                // i == len-1

                    // Validation
                    if (v1[1][S[n][i] - 'A'] > 1 || (v1[0][S[n][i] - 'A'] > 0 && v1[2][S[n][i] - 'A'] > 0))
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        // 2. Test in the entire vector

        // test
        for (int i = 0; i < 26; i++) cout << char ('A' + i) << ' ';
        cout << endl;
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 26; c++) cout << v1[r][c] << ' ';
            cout << endl;
        }
        cout << possible << endl;

        // Connect strings
        string ans;
        if (possible == true) ans = "";
        else ans = "IMPOSSIBLE";

        // Output
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}