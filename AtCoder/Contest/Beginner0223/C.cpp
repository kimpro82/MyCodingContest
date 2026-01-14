// AtCoder Beginner Contest 223
// 2021-10-17(Sun) 21:00 - 22:40, 100 minutes

// C - Doukasen

/* Sample Input & Output
3
1 1
2 1
3 1
3.000000000000000

3
1 3
2 2
3 1
3.833333333333333

5
3 9
1 2
4 6
1 5
5 3
8.916666666666668
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;
    vector<double> A, B;
    double a, b;
    for (int n = 0; n < N; n++)
    {
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }

    // Calculate time and its sum
    vector<double> T;
    double t, total = 0;
    for (int n = 0; n < N; n++)
    {
        t = A[n] / B[n];
        T.push_back(t);
        total += t / 2;                                                 // the two flames will meet

        // test
        // cout << A[n] << ' ' << B[n] << ' ' << t << ' ' << total << endl;
    }

    // Output
    double distance = 0;
    for (int n = 0; n < N; n++)
    {
        if (total - T[n] >= 0)
        {
            distance += A[n];
            total -= A[n] / B[n];
        }
        else if (total > 0)
        {
            distance += total * B[n];
            total = 0;
        }
        else break;

        // test
        // cout << A[n] << ' ' << B[n] << ' ' << A[n] / B[n] << ' ' << total << ' ' << distance << endl;
    }
    cout << distance << endl;

    return 0;
}