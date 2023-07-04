// 5073. Triangles(삼각형과 세 변)
// 2023.07.02

/* Sample input & output data
7 7 7
6 5 4
3 2 5
6 2 6
0 0 0

Equilateral
Scalene
Invalid
Isosceles
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main()
{
    while (true)
    {
        // Input
        vector<int> v;
        int n;
        for (int i = 0; i < 3; i++)
        {
            cin >> n;
            v.push_back(n);
        }
        if (v[0] == 0 && v[1] == 0 && v[2] == 0) break;

        // Operate
        string ans;
        sort(v.begin(), v.end());
        if (v[0] + v[1] > v[2])
        {
            if (v[0] == v[1] && v[1] == v[2]) ans = "Equilateral";
            else if (v[0] == v[1] || v[1] == v[2] || v[2] == v[0]) ans = "Isosceles";
            else ans = "Scalene";
        }
        else ans = "Invalid";

        // Output
        cout << ans << endl;
    }

    return 0;
}
