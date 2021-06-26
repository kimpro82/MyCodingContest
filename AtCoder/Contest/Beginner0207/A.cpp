// AtCoder Beginner Contest 207
// 2021-06-26(Sat) 21:00 - 22:40, 100 minutes

// A - Repression

/* Sample Input & Output
3 4 5
9

6 6 6
12

99 99 98
198
*/


#include <iostream>
#include <vector>
#include <algorithm>    // for sort()

using namespace std;

int main()
{
    vector<int> arr;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());   // by ascending order

    cout << arr[1] + arr[2] << endl;

    return 0;
}