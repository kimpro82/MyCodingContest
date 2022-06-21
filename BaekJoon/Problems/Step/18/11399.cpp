// 11399. ATM

/* Sample input & output data
5
3 1 4 3 2

32
*/


#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
    // Input data
    int n;
    cin >> n;

    vector<int> p;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        p.push_back(temp);
    }

    // Sort in ascending order
    sort(p.begin(), p.end());

    // Count by Greedy algorithm
    int leadTime = 0;
    for (int i = 0; i < n; i++) leadTime += p[i] * (n - i);

    // Output
    cout << leadTime << endl;

    return 0;
}