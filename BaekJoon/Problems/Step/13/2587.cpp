// 2587. 대표값2
// 2023.07.06

/* Sample input & output data
10
40
30
60
30

34
30
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    // Input & Get sum
    vector<int> v;
    int len = 5, sum = 0;
    for (int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
        sum += temp;
    }

    // Sort
    sort(v.begin(), v.end());

    // Output
    cout << sum / len  << endl;
    cout << v[2] << endl;

    return 0;
}
