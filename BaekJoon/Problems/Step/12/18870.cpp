// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 18870. 좌표 압축

/* Sample input & output data
5
2 4 -10 4 -9

2 3 0 3 1
*/

// rather worse performance
// #pragma GCC optimize ("O2")
// #pragma GCC target ("avx")

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define endl '\n'


int main()
{
    // Make it faster
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    // Input N
    int N;
    cin >> N;

    // Input vector<int> and map<int, int>
    vector<int> v;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        v.push_back(x);

        auto it = m.find(x);
        if (it == m.end()) m.insert(pair<int, int>(x, 0));
        else it->second++;
    }

    // Count rank
    int rank = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        it->second = rank;
        rank++;
    }

    // Output
    for (int i = 0; i < N - 1; i++) cout << m.find(v[i])->second << ' ';
    cout << m.find(v[N - 1])->second << endl;

    return 0;
}