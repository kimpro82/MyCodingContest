/* Sample Input & Output
4
2
1 5
4
1 4 2 3
5
10 10 10 10 10
4
7 1 3 1000000

Case #1: 2
Case #2: 3
Case #3: 5
Case #4: 2
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    // Run faster (N <= 10^5)
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input
        int N;
        cin >> N;

        vector<int> S;
        int s, max = 0, maxIdx;
        for (int n = 0; n < N; n++)
        {
            cin >> s;
            S.push_back(s);

            // Find the maximum value's index
            if (s > max) 
            {   max = s;
                maxIdx = n;
            }
        }
        
        // printf("max : %d, maxIdx : %d\n", max, maxIdx);                                              // test
        
        // Count
        int count = 1;
        // 1) 0 ~ maxIdx
        max = S[0];
        for (int n = 1; n <= maxIdx; n++)
        {
            if (S[n] >= max)
            {
                max = S[n];
                count++;
            }
            // cout << n << ' ' << S[n-1] << ' ' << max << ' ' << count << endl;                        // test
        }
        // 2) N-1 ~ maxIdx
        max = S[N-1];
        for (int n = N-1; n >= maxIdx; n--)
        {
            if (S[n] >= max)
            {
                max = S[n];
                count++;
            }
            // cout << n << ' ' << S[n] << ' ' << max << ' ' << count << endl;                          // test
        }
        // 3) find if maxIdx causes double-count
        if (maxIdx == 0)
        {
            if (S[0] >= S[1]) count--;
            // cout << S[0] << ' ' << S[1] << ' ' << count << endl;                                     // test
        }
        else if (maxIdx == N-1)
        {
            if (S[N-2] <= S[N-1]) count--;
            // cout << S[N-2] << ' ' << S[N-1] << ' ' << count << endl;                                 // test
        }
        else
        {
            if (S[maxIdx] >= S[maxIdx-1] && S[maxIdx] >= S[maxIdx+1]) count--;
            // cout << S[maxIdx-1] << ' ' << S[maxIdx] << ' ' << S[maxIdx+1] << ' ' << count << endl;   // test
        }

        // Output
        cout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}