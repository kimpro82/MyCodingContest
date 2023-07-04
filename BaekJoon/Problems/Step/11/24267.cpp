// 24267. 알고리즘 수업 - 알고리즘의 수행 시간 6
// 2023.07.04

/* Sample input & output data
7

35
3
*/


#include <iostream>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    // Input
    long long n;
    cin >> n;

    // Operate : Trial 1 - Time Limit Exceeded
    // long long cnt = 0;
    // for (int i = 1; i <= n - 2; i++)
    // {
    //     for (int j = i + 1; j <= n - 1; j++)
    //     {
    //         for (int k = j + 1; k <= n; k++)
    //         {
    //             cnt++;

    //             #ifdef test
    //                 printf("%d %d %d\n", i, j, k);
    //             #endif
    //         }
    //     }
    // }

    // Operate : Trial 2
    long long cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        cnt += (n - i - 1) * (n - i) / 2;

        #ifdef test
            printf("%d %d\n", i, cnt);
        #endif
    }

    // Output
    cout << cnt << endl;
    cout << 3 << endl;

    return 0;
}
