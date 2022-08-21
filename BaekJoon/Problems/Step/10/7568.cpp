// [BOJ] 단계별로 풀어보기 > 11. 브루트 포스

// 7568. 덩치

/* Sample input & output data
5
55 185
58 183
88 186
60 175
46 155

2 2 1 2 5
*/


#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
    // Input
    int N;
    cin >> N;

    // Input x, y
    int x, y;
    vector<vector<int>> xy;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        xy.push_back(temp);
    }

    // Determine everyone's ranking
    vector<int> ranking;
    for (int i = 0; i < N; i++)
    {
        int onesRank = 1;
        for (int j = 0; j < N; j++) if (xy[i][0] < xy[j][0] && xy[i][1] < xy[j][1]) onesRank++;
        ranking.push_back(onesRank);
    }

    // Output
    for (int i = 0; i < N - 1; i++) cout << ranking[i] << ' ';
    cout << ranking[N - 1] << endl;

    return 0;
}