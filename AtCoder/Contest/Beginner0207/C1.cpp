// AtCoder Beginner Contest 207
// 2021-06-26(Sat) 21:00 - 22:40, 100 minutes

// C - Many Segments

/* Sample Input & Output
3
1 1 2
2 2 3
3 2 4

2
*/


#include <iostream>

using namespace std;

int main()
{
    // input data : n
    int n;
    cin >> n;

    // input data : t, l, r
    int interval[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> interval[i][0] >> interval[i][1] >> interval[i][2];
    }

    // determine if intersect
    int count = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if ((interval[j][0] == 1 || interval[j][0] == 3) && (interval[k][0] == 1 || interval[k][0] == 2))
            // ?j] vs [k?
            {
                if ((interval[j][1] < interval[k][2]) && (interval[j][2] >= interval[k][1]))
                {
                    count++;
                }
            }
            else if ((interval[j][0] == 1 || interval[j][0] == 2) && (interval[k][0] == 1 || interval[k][0] == 3))
            // ?k] vs [j?
            {
                if ((interval[j][1] <= interval[k][2]) && (interval[j][2] > interval[k][1]))
                {
                    count++;
                }
            }
            else
            // ?j) vs (k? / ?k) vs (j? 
            {
                if ((interval[j][1] < interval[k][2]) && (interval[j][2] > interval[k][1]))
                {
                    count++;
                }
            }

            // test
            cout << interval[j][1] << " " << interval[j][2] << " "
                << interval[k][1] << " " << interval[k][2] << " " << count << endl;
        }
    }

    cout << count << endl;

    return 0;
}