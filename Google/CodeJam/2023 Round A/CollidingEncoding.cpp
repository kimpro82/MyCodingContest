/* Sample Input & Output
2
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
4
ABC
BC
BCD
CDE
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
3
CDE
DEF
EFG

Case #1: NO
Case #2: YES
*/


#include <iostream>
#include <vector>
#include <set>
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

    for (int t = 1; t <= T; t++)
    {
        // Input 26 disits into vector<char> D
        vector<char> D;
        for (int d = 0; d < 26; d++)
        {
            char temp;
            cin >> temp;
            D.push_back(temp);
        }
        #ifdef test
            cout << "\n<test>" << endl;
            for (int d = 0; d < 26; d++) cout << D[d];
            cout << endl;
        #endif

        // Input N words into vector<string> S
        int N;
        cin >> N;
        vector<string> S;
        for (int n = 0; n < N; n++)
        {
            string temp;
            cin >> temp;
            S.push_back(temp);
        }
        #ifdef test
            for (int n = 0; n < N; n++) cout << S[n] << ' ';
            cout << endl;
        #endif

        // Encoding
        set<string> Encoded;                                                    // not <int> because of 0xx
        string ans = "NO";
        for (int n = 0; n < N; n++)
        {
            int len = S[n].size();
            string encoded;
            for (int i = 0; i < len; i++) encoded += D[S[n][i] - 'A'];

            #ifdef test
                cout << encoded << ' ';
            #endif

            // Binary search to find if there's the same encoded number to each other
            if (Encoded.find(encoded) == Encoded.end()) Encoded.insert(encoded);// no same element → no collision
            else                                                                // → a collision
            {
                ans = "YES";
                break;
            }
        }

        // Output
        #ifdef test
            cout << endl;
        #endif
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}