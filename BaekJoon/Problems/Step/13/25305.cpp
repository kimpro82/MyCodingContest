// 25305. 커트라인
// 2023.07.06

/* Sample input & output data
5 2
100 76 85 93 98

98
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    // Declare
    int n, k;
    vector<int> v;

    // Input
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    // Sort
    sort(v.begin(), v.end());

    // Output
    cout << v[n - k] << endl;

    return 0;
}
