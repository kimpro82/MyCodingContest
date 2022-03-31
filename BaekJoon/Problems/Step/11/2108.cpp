// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 2108. 통계학

/* Sample input & output data
5
1
3
8
-2
2

2
2
1
10
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int main()
{
    // Input N
    int N;
    cin >> N;

    // Input numbers
    vector<int> v, modeCandidate;
    map<int, int> m;
    int sum = 0, modeFreq = 0, max = -4000, min = 4000;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        // 1. Mean
        sum += n;                                                           // 4,000 * 500,000 = 2,000,000,000 < __int_max__

        // 2. Median
        v.push_back(n);

        // 3. Mode
        auto mFind = m.find(n);
        if (mFind == m.end()) m.insert(pair<int, int>(n, 1));
        else mFind->second++;
        mFind = m.find(n);                                                  // avoid mFind == m.end()
        if (mFind->second > modeFreq) modeFreq = mFind->second;

        // test
        // cout << mFind->first << ' ' << mFind->second << ' ' << modeFreq << endl;

        // 4. Max - Min
        if (n < min) min = n;
        if (n > max) max = n;
    }

    // 2. Median : sort by ascending order
    sort(v.begin(), v.end());

    // 3. Mode : the given condition is like trash ……
    int mode;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == modeFreq) modeCandidate.push_back(it->first);
        if (modeCandidate.size() > 2) break;
    }
    if (modeCandidate.size() == 1) mode = modeCandidate[0];
    else mode = modeCandidate[1];

    // Output
    cout << round((double) sum / N) << endl;                                // 1. Mean
    cout << v[(N - 1) / 2] << endl;                                         // 2. Median
    cout << mode << endl;                                                   // 3. Mode
    cout << max - min << endl;                                              // 4. Max - Min

    return 0;
}