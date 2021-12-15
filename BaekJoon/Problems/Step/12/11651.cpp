// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 11651. 좌표 정렬하기 2

/* Sample input & output data
5
0 4
1 2
1 -1
2 2
3 3

1 -1
1 2
2 2
3 3
0 4
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

bool comp(pair<int, int> v1, pair<int, int> v2)             // only different part from Q.11650
{
    if (v1.second == v2.second) return v1.first < v2.first;
    else return v1.second < v2.second;
}


int main()
{
    // Input N
    int N;
    cin >> N;

    // Input vector<pair<int, int>>
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        int temp1, temp2;
        pair<int, int> p;
        cin >> temp1 >> temp2;
        p.first = temp1;
        p.second = temp2;
        v.push_back(p);
    }

    // Sort
    sort(v.begin(), v.end(), comp);

    // Output
    for (int i = 0; i < N; i++) cout << v[i].first << ' ' << v[i].second << endl;

    return 0;
}