// AtCoder Beginner Contest 213
// 2021-08-08(Sun) 21:00 - 22:40, 100 minutes

// B - Booby Prize

/* Sample Input & Output
6
1 123 12345 12 1234 123456
3

5
3 1 4 15 9
5
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int N;
    cin >> N;

    int temp;
    vector<int> v;
    for (int n = 0; n < N; n++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    // Copy vector v and sort
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());

    // Find the index in v that is the same with the [N-1]-th element in v2
    int prize = v2[N-2], ans;
    for (int i = 0; i < N; i++)
    {
        if (v[i] == prize)
        {
            ans = i + 1;
            break;
        }
    }

    // Output
    cout << ans << endl;

    return 0;
}