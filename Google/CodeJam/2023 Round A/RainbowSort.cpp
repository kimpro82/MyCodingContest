/* Sample Input & Output
2
4
3 8 8 2
5
3 8 2 2 8

Case #1: 3 8 2
Case #2: IMPOSSIBLE
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
        bool ansFlag = true;

        // Input data into vector S
        int N;
        cin >> N;
        vector<int> S;
        for (int n = 0; n < N; n++)
        {
            int temp;
            cin >> temp;
            S.push_back(temp);
        }

        #ifdef test
            cout << "\n<test>" << endl;
        #endif

        // Save a vector v and a set ans at the same time
        vector<int> V;
        set<int> ANS;
        for (int n = 0; n < N; n++)
        {
            #ifdef test
                cout << S[n] << ' ';
            #endif

            // Find if possible or not
            if (n == 0)
            {
                V.push_back(S[n]);
                ANS.insert(S[n]);
            }
            else if (S[n] != S[n-1])
            {
                if (ANS.find(S[n]) == ANS.end())
                {
                    V.push_back(S[n]);
                    ANS.insert(S[n]);
                }
                else
                {
                    ansFlag = false;
                    break;
                }
            }
        }
        #ifdef test
            cout << endl;
        #endif

        // Output
        cout << "Case #" << t << ": ";
        if (ansFlag)
        {
            for (int i = 0; i < V.size(); i++) cout << V[i] << ' ';
            cout << endl;;
        }
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}