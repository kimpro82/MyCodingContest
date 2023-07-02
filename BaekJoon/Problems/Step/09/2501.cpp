// 2501. 약수 구하기
// 2023.07.02

/* Sample input & output data
6 3

3
*/


#include <iostream>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    int a, b;

    // Input
    cin >> a >> b;

    int cnt = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt++;

            // Test
            #ifdef test
                printf("i:%d remainder:%d cnt:%d\n", i, a%i, cnt);
            #endif

            // Operate and Output
            if (cnt == b)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
