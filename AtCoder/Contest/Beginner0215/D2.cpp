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
#include <set>
#include <cmath>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N, M, temp;
    cin >> N >> M;
    vector<int> A;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        A.push_back(temp);
    }

    // Operation : Sieve of Eratosthenes
    vector<bool> candidate (M + 1, true);
    for (int n = 0; n < N; n++)
    {
        // get A[n]'s prime factors (minimal)
        set<int> pFactor;
        int divisor = 2;
        while (A[n] > 1)
        {
            if (A[n] % divisor == 0)
            {
                pFactor.insert(divisor);
                A[n] /= divisor;
            }
            else divisor++;
        }

        // test
        cout << endl << "test : " << n + 1 << endl;
        for (auto it = pFactor.begin(); it != pFactor.end(); it++) cout << *it << ' ';
        cout << endl << endl;

        // record false at all the multiples of pFactor's elements
        for (auto it = pFactor.begin(); it != pFactor.end(); it++)
        {
            for (int fm = 0; fm < M + 1; fm += *it) candidate[fm] = false;
        }
    }

    // Output
    vector<int> prime;
    for (int m = 1; m <= M; m++)
    {
        if (candidate[m] == true) prime.push_back(m);
    }
    int pSize = prime.size();
    cout << pSize << endl;
    for (int p = 0; p < pSize; p++) cout << prime[p] << endl;

    return 0;
}