// 2720. Quick Change (세탁소 사장 동혁)
// 2023.06.28

/* Sample input & output data
3
124
25
194

4 2 0 4
1 0 0 0
7 1 1 4
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input : 1 <= C <= 500
    int T, c;
    cin >> T;
    vector<int> C;
    for (int t = 0; t < T; t++)
    {
        cin >> c;
        C.push_back(c);
    }

    // Operate & Output
    vector<int> v = {25, 10, 5, 1};
    int len = v.size();
    for (int t = 0; t < T; t++)
    {
        vector<int> cnt(len, 0);
        for (int i = 0; i < len; i++)
        {
            cnt[i] += C[t] / v[i];
            C[t] -= cnt[i] * v[i];

            cout << cnt[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
