// 1764. 듣보잡
// 2023.07.08

/* Sample input & output data
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

2
baesangwook
ohhenrie
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

    // Input n
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        mp[temp] = 1;
    }

    // Input m
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (mp.find(temp) == mp.end()) mp[temp] = 1;
        else
        {
            mp[temp]++;
            cnt++;
        }
    }

    // Output
    cout << cnt << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) if (it->second == 2) cout << it->first << endl;

    return 0;
}
