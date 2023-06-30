// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 4153. Egypt (직각삼각형)

/* Sample input & output data
6 8 10
25 52 60
5 12 13
0 0 0

right
wrong
right
*/


#include <iostream>
// #include <array>     // not used, but use legacy array
#include <algorithm>    // sort()
#include <cmath>        // pow()

using namespace std;
#define endl '\n'

int main()
{
    int arr[3];
    // array<int, 3> arr                            // causes crazy compile time error when apply to sort()
    while (true)
    {
        // Input data
        for (int i = 0; i < 3; i++) cin >> arr[i];
        if (arr[0] == 0) break;                     // enough to check just one line segment

        // Sort : not sure if data will be sorted
        sort(arr, arr + 3);                         // not sort(arr[0], arr[3])

        // Output
        if ((int) pow(arr[0], 2) + (int) pow(arr[1], 2) == (int) pow(arr[2], 2))
        {
            cout << "right" << endl;
        } else
        {
            cout << "wrong" << endl;
        }
    }

    return 0;
}