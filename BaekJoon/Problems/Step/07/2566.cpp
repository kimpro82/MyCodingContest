// 2566. 최댓값
// 2023.06.26

/* Sample input & output data
3 23 85 34 17 74 25 52 65
10 7 39 42 88 52 14 72 63
87 42 18 78 53 45 18 84 53
34 28 64 85 12 16 75 36 55
21 77 45 35 28 75 90 76 1
25 87 65 15 28 11 37 28 74
65 27 75 41 7 89 78 64 39
47 47 70 45 23 65 3 41 44
87 13 82 38 31 12 29 29 80

90
5 7
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int row = 9, col = 9;
    int max = 0, maxRow = 1, maxCol = 1;                    // maxRow, maxCol should also have their initial values againt when max == 0

    // Input
    int temp;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> temp;
            if (temp > max)
            {
                max = temp;
                maxRow = i;
                maxCol = j;
                if (max == 100) break;
            }
        }
        if (max == 100) break;
    }

    // Output
    cout << max << endl;
    cout << maxRow << ' ' << maxCol << endl;

    return 0;
}