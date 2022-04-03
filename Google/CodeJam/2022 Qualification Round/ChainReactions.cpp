/* Sample Input & Output
3
4
60 20 40 50
0 1 1 2
5
3 2 1 4 5
0 1 1 1 0
8
100 100 100 90 80 100 90 100
0 1 2 1 2 3 1 3

Case #1: 110
Case #2: 14
Case #3: 490
*/


#include <iostream>
#include <vector>
#include <set>
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

        vector<int> F, P;
        int f, p;
        for (int n = 0; n < N; n++)
        {
            cin >> f;
            F.push_back(f);
        }
        for (int n = 0; n < N; n++)
        {
            cin >> p;
            P.push_back(p);
        }

        // Find initiators (that aren't pointed)
        vector<int> PCounting(N, 1);                                                    // mark 0 or 1 on a vector
        for (int n = 0; n < N; n++) PCounting[P[n] - 1] = 0;                            // why doesn't [-1] occur an error?
        vector<int> Initiators;
        for (int n = 0; n < N; n++) if (PCounting[n] > 0) Initiators.push_back(n + 1);  // + 1 : crazy
        int initLen = Initiators.size();

        // test : ok
        for (int n = 0; n < N; n++) cout << PCounting[n] << ' ';
        cout << endl;
        for (int i = 0; i < initLen; i++) cout << Initiators[i] << ' ';
        cout << endl;

        // Operate the permutations of Initiators
        int sum = 0, max = 0, passedSum, pointer;
        do
        {
            // test : ok
            // for (int i = 0; i < initLen; i++) cout << Initiators[i] << ' ';
            // cout << endl;

            vector<int> passed(initLen, 0);
            sum = 0, passedSum = 0, pointer;
            while (passedSum < initLen)
            {
                // recursion required
                passedSum++;
            }

            if (sum > max) max = sum;
        }
        while (next_permutation(Initiators.begin(), Initiators.end()));

        // Output
        cout << "Case #" << t << ": " << max << endl;
    }

    return 0;
}