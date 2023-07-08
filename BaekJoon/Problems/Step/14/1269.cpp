// 1269. 대칭 차집합
// 2023.07.08

/* Sample input & output data
3 5
1 2 4
2 3 4 5 6

4
*/


#include <iostream>
#include <map>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    // Fast I/O
    cin.tie(0);
	ios::sync_with_stdio(false);

    // Input n & m
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int temp;
    for (int i = 0; i < n + m; i++)
    {
        cin >> temp;
        if (mp.find(temp) == mp.end()) mp[temp] = 1;
        else mp[temp]++;
    }
    // not guaranteed that there's no duplicated elements in a set

    // Output
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) if (it->second == 1) cnt++;
    cout << cnt << endl;

    return 0;
}
