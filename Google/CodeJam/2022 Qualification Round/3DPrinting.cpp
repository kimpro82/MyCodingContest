/* Sample Input & Output
3
300000 200000 300000 500000
300000 200000 500000 300000
300000 500000 300000 200000
1000000 1000000 0 0
0 1000000 1000000 1000000
999999 999999 999999 999999
768763 148041 178147 984173
699508 515362 534729 714381
949704 625054 946212 951187

Case #1: 300000 200000 300000 200000
Case #2: IMPOSSIBLE
Case #3: 400001 100002 100003 399994
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        // Input
        int cmyk[3][4];
        int min[4] = {1000000, 1000000, 1000000, 1000000};          // crazy but excused because this is competitive programming
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> cmyk[i][j];

                if (cmyk[i][j] < min[j]) min[j] = cmyk[i][j];
            }
        }

        // Find if the sum of minimum inks meets 1,000,000
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            if (sum >= 1000000) min[j] = 0;
            else if (sum + min[j] >= 1000000) min[j] = 1000000 - sum;

            sum += min[j];
        }

        // Output
        cout << "Case #" << t << ": ";
        if (sum == 1000000) for (int j = 0; j < 4; j++) cout << min[j] << ' ';
        else cout << "IMPOSSIBLE";
        cout << endl;
    }

    return 0;
}