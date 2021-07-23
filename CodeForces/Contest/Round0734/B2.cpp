// Codeforces Round #734 (Div. 3)
// 2021.07.23 23:35, 2 hrs

// B2. Wonderful Coloring - 2

/* Sample Input & Output
6
10 3
3 1 1 1 1 10 3 10 10 2
4 4
1 1 1 1
1 1
1
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9
13 2
3 1 4 1 5 9 2 6 5 3 5 8 9
13 3
3 1 4 1 5 9 2 6 5 3 5 8 9

1 1 0 2 3 2 2 1 3 3
4 2 1 3
1
0 0 1 1 0 1 1 1 0 1 1 1 0
2 1 2 2 1 1 1 1 2 1 0 2 2
1 1 3 2 1 3 3 1 2 2 3 2 0
*/


#include <iostream>
#include <map>
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
        int n, k;               // n : the length of a given sequence
        cin >> n >> k;          // k : the number of colors

        // Make map m
        map<int, int> m;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;;
            if (m.find(temp) == m.end()) m.insert(pair<int, int> (temp, 1));
            else m.find(temp)->second += 1;
        }

        // test : ok
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            cout << it->first << ' ' << it->second << " / ";
        }
        cout << "\b\b\b" << endl;                               // '\b' doesn't work

        // Convert map m to vector v;
        vector<pair<int, int>> v(m.begin(), m.end());

        // test : ok
        for (int l1 = 0; l1 < v.size(); l1++) cout << v[l1].first << ' ';
        cout << endl;        
        for (int l2 = 0; l2 < v.size(); l2++) cout << v[l2].second << ' ';
        cout << endl;

        // need more codes ……
;
    } // The end of t loop

    return 0;
}