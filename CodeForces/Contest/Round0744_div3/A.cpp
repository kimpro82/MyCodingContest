// Codeforces Round #744 (Div. 3)
// 2021.09.28 23:35, 2.25 hrs

// A. Casimir's String Solitaire

/* Sample Input & Output
6
ABACAB
ABBA
AC
ABC
CABCBB
BCBCBCBCBCBCBCBC

NO
YES
NO
NO
YES
YES
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        string s;
        cin >> s;
        int len = s.length();

        // Count
        vector<int> v (3, 0);
        for (int j = 0; j < len; j++) v[s[j] - 'A']++;    // Crazy!

        // test
        for (int k = 0; k < 3; k++) cout << v[k] << ' ';
        cout << endl;

        // Output
        string ans = "NO";
        if (len %2 == 0) if (v[0] + v[2] == v[1]) ans = "YES";
        cout << ans << endl;
    }

    return 0;
}