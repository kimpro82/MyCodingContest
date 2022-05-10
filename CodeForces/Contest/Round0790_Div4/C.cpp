// Codeforces Round #790 (Div. 4)
// 2022.05.10 23:45, 2 hrs

// C. Most Similar Words

/* Sample Input & Output
6
2 4
best
cost
6 3
abb
zba
bef
cdu
ooo
zzz
2 7
aaabbbc
bbaezfe
3 2
ab
ab
ab
2 8
aaaaaaaa
zzzzzzzz
3 1
a
u
y

11
8
35
0
200
4
*/


#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        // Input data
        int n, m;                                       // 2 <= n <= 50, 1 <= m <= 8
        cin >> n >> m;
 
        vector<string> s;
        string temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            s.push_back(temp);
        }
        
        // Solve
        int sum, min = 1000;
        for (int k = 0; k < n - 1; k++)
        {
            for (int l = k + 1; l < n; l++)
            {
                sum = 0;
                for (int o = 0; o < m; o++) sum += abs(s[k][o] - s[l][o]);
                if (sum < min) min = sum;

                // test
                // printf("%d %d %d %d\n", k, l, sum, min);
                // printf("%d %d %s %s %d %d\n", k, l, s[k], s[l], sum, min);   // %s %s work something wrong
            }
        }

        // Output
        cout << min << endl;
    }

    return 0;
}