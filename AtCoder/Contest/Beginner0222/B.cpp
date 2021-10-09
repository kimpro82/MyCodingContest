// AtCoder Beginner Contest 222
// 2021-10-09(Sat) 21:00 - 22:40, 100 minutes

// B - Failing Grade

/* Sample Input & Output
4 50
80 60 40 0
2

3 90
89 89 89
3

2 22
6 37
1
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    int N, P, a;
    vector<int> A;

    cin >> N >> P;
    for (int n = 0; n < N; n++)
    {
        cin >> a;
        A.push_back(a);
    }

    int cnt = 0;
    for (int n = 0; n < N; n++) if (A[n] < P) cnt++;

    cout << cnt << endl;

    return 0;
}