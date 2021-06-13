/* Sample input & output data
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

40.000%
57.143%
33.333%
66.667%
55.556%
*/

#include <iostream>

using namespace std;

int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;

        // get sum and average
        int scores[n], sum = 0, average;
        for (int j = 0; j < n; j++)
        {
            cin >> scores[j];
            sum += scores[j];
        }
        average = sum / n;

        // get percentage of students whose grade is above average
        double aboveAverage = 0;
        for (int k = 0; k < n; k++)
        {
            if (scores[k] > average)
            {
                aboveAverage += 1;
            }
        }

        // test
        // cout << n << " " << sum << " " << average << " " << aboveAverage << endl;

        // ouput
        double aboveAverageRatio = (double) (aboveAverage / n) * 100;
        cout << fixed;      // output 40.000, not 40
        cout.precision(3);  // 3 : 3 ciphers under decimal point
        cout << aboveAverageRatio << '%' << endl;
    }

    return 0;
}