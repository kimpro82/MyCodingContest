// 2485. 가로수
// 2023.07.09

/* Sample input & output data
4
2
6
12
18

5
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    int n;
    cin >> n;

    // Input & Operate 1 : Find the shortest distance
    vector<int> v;
    int dist = 1000000000;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);

        if (i > 0 && v[i] - v[i-1] < dist) dist = v[i] - v[i-1];
    }

    // Operate 2 : Count trees newly planted
    int ans = 0;
    int loc = v[0];
    while (loc < v[n-1])
    {
        loc += dist;
        if (binary_search(v.begin(), v.end(), loc)) continue;
        else ans++;
    }

    // Output
    cout << ans << endl;

    return 0;
}


/*
4
2
6
12
18

2
*/
