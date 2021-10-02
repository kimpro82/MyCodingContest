// AtCoder Beginner Contest 221
// 2021-10-02(Sat) 21:00 - 22:40, 100 minutes

// D - Online games

/* Sample Input & Output
3
1 2
2 3
3 1

2 2 0

2
1000000000 1000000000
1000000000 1000000000

0 1000000000
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;
    vector<vector<int>> v;
    int a, b;
    for (int n = 0; n < N; n++)
    {
        vector<int> v2;
        cin >> a >> b;
        v2.push_back(a);
        v2.push_back(b);
        v.push_back(v2);
    }

    // Output
    int ans = 0, waterMark = 0;
    for (int n = 0; n < N; n++)
    {
        ans = max(0, v[n][1] - max(v[n][0], waterMark) + 1);
        waterMark = max(waterMark, v[n][0] + v[n][1] - 1);

        // test
        cout << n << ' ' << v[n][0] << ' ' << v[n][1] << ' ' << waterMark << ' ' << ans << endl;

        // cout << ans << ' ';
    }
    cout << endl;

    return 0;
}