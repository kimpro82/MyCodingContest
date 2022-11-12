// AtCoder Beginner Contest 277
// 2022-11-12(Sat) 21:00 - 22:40, 100 minutes

// B - Playing Cards Validation

/* Sample Input & Output
4
H3
DA
D3
SK

5
H3
DA
CK
H3
S7

4
3H
AD
3D
KS

5
00
AA
XX
YY
ZZ

Yes
No
No
No
*/


#include <iostream>
#include <vector>

#define DEBUG
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;
    vector<string> S;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        S.push_back(temp);
    }

    // Determine Yes or No
    vector<char> con1 = {'H', 'D', 'C', 'S'};
    vector<char> con2 = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    bool determine;
    for (int i = 0; i < N; i++)
    {
        #ifdef DEBUG
            cout << i << ' ' << S[i] << ' ';
        #endif

        // Condition 1
        determine = false;
        for (int j = 0; j < 4; j++)
        {
            if (S[i][0] == con1[j])
            {
                determine = true;
                break;
            }
        }
        #ifdef DEBUG
            cout << determine << ' ';
        #endif
        if (determine == false) break;

        // Condition 2
        bool determine = false;
        int len = con2.size();
        for (int j = 0; j < len; j++)
        {
            if (S[i][1] == con2[j])
            {
                determine = true;
                break;
            }
        }
        #ifdef DEBUG
            cout << determine << ' ';
        #endif
        if (determine == false) break;

        // Condition 3
        for (int j = i + 1; j < N; j++)
        {
            if (S[i] == S[j])
            {
                determine = false;
                break;
            }
        }
        #ifdef DEBUG
            cout << determine << endl;
        #endif
        if (determine == false) break;
    }
    #ifdef DEBUG
        cout << determine << endl;
    #endif

    // Output
    string ans = (determine == true) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}