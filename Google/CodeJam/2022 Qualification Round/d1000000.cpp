/* Sample Input & Output
4
4
6 10 12 8
6
5 4 5 4 4 4
10
10 10 7 6 7 4 4 5 7 4
1
10

Case #1: 4
Case #2: 5
Case #3: 9
Case #4: 1
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

        vector<int> S = {0};
        int s;
        for (int n = 1; n <= N; n++)
        {
            cin >> s;
            S.push_back(s);
        }

        // Count
        int count = 0, criterion = 1;
        sort(S.begin(), S.end());
        for (int n = 1; n <= N; n++)
        {
            if (S[n] >= criterion)
            {
                count++;
                criterion++;
            }
        }

        // Output
        cout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}