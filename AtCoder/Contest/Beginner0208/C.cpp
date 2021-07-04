// AtCoder Beginner Contest 208
// 2021-07-04(Sun) 21:00 - 22:40, 100 minutes

// C - Fair Candy Distribution

/* Sample Input & Output
2 7
1 8
4
3

1 3
33
3

7 1000000000000
99 8 2 4 43 5 3
142857142857
142857142857
142857142858
142857142857
142857142857
142857142857
142857142857
*/


#include <iostream>
#include <vector>
#include <algorithm>    // for sort()

using namespace std;

int main()
{
    int n, k, temp;
    vector<int> a;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    // when sweets more than n

    // when allocate sweets from citizens with the smaller ID number

    // output

    return 0;
}