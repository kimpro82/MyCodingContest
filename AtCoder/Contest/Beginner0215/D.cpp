// AtCoder Beginner Contest 215
// 2021-08-21(Sat) 21:00 - 22:40, 100 minutes

// D - Coprime 2

/* Sample Input & Output
3 12
6 1 5

3
1
7
11
*/


#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    int N, M, temp;
    cin >> N >> M;
    vector<int> A;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        A.push_back(temp);
    }

    vector<int> prime;
    int Max, Min, mod;
    for (int n = 0; n <= n; n++)
    {
        for (int m = 1; m <= M; m++)
        {
            Max = max(A[n], m);
            Min = min(A[n], m);
            mod = Max;

            while (mod != 0)
            {
                mod = Max % Min;
                Max = Min;
                Min = mod;
            }
        
            // test
            cout << A[n] << ' ' << m << ' ' << Max << endl;
        }

        if (Max = 1) prime.push_back(Max);
    }

    // Output
    int pSize = prime.size();
    cout << pSize << endl;
    for (int p = 0; p < pSize; p++) cout << prime[p] << endl;

    return 0;
}