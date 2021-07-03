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

    // input data : t, l[n], r[n] + reflect brackets with tricky way
    int t;
    double interval[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> t >> interval[i][0] >> interval[i][1];
        if (t == 3 || t == 4)   // (l
        {
            interval[i][0] += 0.1;
        }
        if (t == 2 || t == 4)   // r)
        {
            interval[i][1] -= 0.1;
        }
    }

    // determine if intersect
    int count = 0;
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            // my code
            if ((interval[j][0] <= interval[k][1]) && (interval[j][1] >= interval[k][0]))
            {
                count++;
            }

            // cheating code
            // if (max(interval[j][0], interval[k][0]) <= min(interval[j][1], interval[k][1]))
            // {
            //     count++;
            // }

            // test
            cout << interval[j][0] << " " << interval[j][1] << " "
                << interval[k][0] << " " << interval[k][1] << " " << count << endl;
        }
    }

    cout << count << endl;

    return 0;
}