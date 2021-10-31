// [BOJ] 단계별로 풀어보기 > 11. 브루트 포스

// 2231. Digit Generator

/* Sample input & output data
216

198
*/


#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
    // Input
    int N;
    cin >> N;

    // Count N's digits
    int n = N, digits = 1;
    while (n > 10)
    {
        n /= 10;
        digits++;
    }

    // Assume a minimum generator candidate
    int min = max(0, N - 9 * digits);

    // Find the minimum generator
    int disitSum;
    string candidate;
    bool ok = false;
    for (int i = min; i < N; i++)
    {
        disitSum = i;
        candidate = to_string(i);

        for (int j = 0; j < candidate.size(); j++) disitSum += candidate[j] - '0';

        // test
        // cout << N << ' ' << digits << ' ' << candidate << ' ' << disitSum << endl;

        if (disitSum == N)
        {
            ok = true;
            break;
        }
    }

    // Output
    if (!ok) cout << 0 << endl;
    else cout << candidate << endl;

    return 0;
}