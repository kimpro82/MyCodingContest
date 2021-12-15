// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 11650. 좌표 정렬하기

/* Sample input & output data
5
3 4
1 1
1 -1
2 2
3 3

1 -1
1 1
2 2
3 3
3 4
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

bool comp(pair<int, int> v1, pair<int, int> v2)             // I've just learned a new skill!
{
    if (v1.first == v2.first) return v1.second < v2.second;
    else return v1.first < v2.first;
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