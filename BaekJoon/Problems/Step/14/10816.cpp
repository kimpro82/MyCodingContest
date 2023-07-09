// 10816. 숫자 카드 2
// 2023.07.08

/* Sample input & output data
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

3 0 0 1 2 0 0 2
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
    int n;
    cin >> n;
    map<int, int> mp;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (mp.find(temp) == mp.end()) mp.insert(pair<int, int> (temp, 1));
        else mp[temp]++;
    }

    // Input m & Output
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (mp.find(temp) == mp.end()) cout << 0 << ' ';
        else cout << mp[temp] << ' ';                                           // not mp[temp]->second
    }
    cout << endl;

    return 0;
}
