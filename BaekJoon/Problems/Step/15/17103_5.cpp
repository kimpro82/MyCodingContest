// 17103. 골드바흐 파티션
// 2023.07.11

/* Sample input & output data
5
6
8
10
12
100

1
1
2
1
6
*/


#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;


// Use the sieve of Eratosthenes
void eratos(int* vPtr, const int* NUM)
{
    for (int i = 2; i <= *NUM; i++)
    {
        if (vPtr[i] == 1)
        {
            #ifdef test
                cout << i << ' ';
            #endif

            for (int j = i + i; j <= *NUM; j += i) vPtr[j] = 0;                 // run only when i is a prime number
        }
    }

    #ifdef test
        cout << endl;
    #endif
}

int main()
{
    // First, get a sorted vector of prime numbers between 2 and 1m
    #ifdef test
        const int NUM = 100;
    #else
        const int NUM = 1'000'000;                                              // add digit separators
    #endif
    vector<int> v(NUM + 1, 1);
    int* vPtr = v.data();                                                       // declare pointer for v
    eratos(vPtr, &NUM);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Count when `j` and `j - n` both exist
        int cnt = 0;
        for (int j = 2; j <= n / 2; j++)
        {
            if (v[j] == 1 && v[n-j] == 1)                                       // O(n * log_n) → O(n) : It was binary search that was the criminal!
            {
                cnt++;

                #ifdef test
                    printf("a:%d b:%d cnt:%d\n", j, n - j, cnt);
                #endif
            }
        }

        cout << cnt << endl;
    }

    return 0;
}

// 맞았습니다!!
