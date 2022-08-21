/* Sample input & output data
3
40 80 60

75.0
*/

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    double score[t], maxValue = 0, sum = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> score[i];
        maxValue = max(maxValue, score[i]);
    }

    for (int j = 0; j < t; j++)
    {
        score[j] *= (1 / maxValue) * 100;
        sum += score[j];
    }

    cout << sum / t << endl;

    return 0;
}