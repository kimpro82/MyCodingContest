// [BOJ] 단계별로 풀어보기 > 11. 브루트 포스

// 1436. 영화감독 숌

/* Sample input & output data
2
1666

3
2666

6
5666

187
66666

500
166699
*/


#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
    // Input N
    int N ;         // 1 <= N <= 10000
    cin >> N;

    // Find the 666-number
    int n = 666, count = 0;
    while (true)
    {
        string stringN = to_string(n);
        int len = stringN.length();

        for (int i = 0; i < len - 3 + 1; i++)
        {
            if (stringN.substr(i, 3) == "666")
            {
                count++;

                // test
                // cout << n << ' ' << count << endl;

                break;
            }
        }

        if (count == N) break;

        n++;
    }

    // Output
    cout << n << endl;

    return 0;
}