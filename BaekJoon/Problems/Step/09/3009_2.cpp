// [BOJ] 단계별로 풀어보기 > 9. 기본 수학 2

// 3009. 네 번째 점

/* Sample input & output data
5 5
5 7
7 5

7 7

30 20
10 10
10 20

30 10
*/


#include <iostream>
#include <array>

using namespace std;
#define endl '\n'

int main()
{
    // Input data
    array<int, 1001> x = {0, }, y = {0, };
    int temp1, temp2;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp1 >> temp2;
        x[temp1]++;
        y[temp2]++;
    }

    // test
    for (int j = 1; j <= 1000; j++)
    {
        if (x[j] != 0) cout << "x : " << j << ' ' << x[j] << endl;
        if (y[j] != 0) cout << "y : " << j << ' ' << y[j] << endl;
    }     

    // Find the 4th point
    int x4 = 0, y4 = 0;
    for (int k = 1; k <= 1000; k++)
    {
        if (x[k] == 1) x4 = k;
        if (y[k] == 1) y4 = k;
        if (x4 != 0 && y4 != 0) break;  // a little sincere attitude, not much
    }   

    // // Output
    cout << x4 << ' ' << y4 << endl;

    return 0;
}