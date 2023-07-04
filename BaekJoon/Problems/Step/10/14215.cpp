// 14215. 세 막대
// 2023.07.02

/* Sample input & output data
41 64 16

113
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    // Input
    vector<int> v;
    int n;
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    // Operate
    sort(v.begin(), v.end());
    if (v[0] + v[1] <= v[2]) v[2] = v[0] + v[1] - 1;

    // Output
    int sum = v[0] + v[1] + v[2];
    cout << sum << endl;

    return 0;
}
