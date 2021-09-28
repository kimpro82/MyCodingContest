// Codeforces Round #744 (Div. 3)
// 2021.09.28 23:35, 2.25 hrs

// B. Shifting Sort

/* Sample Input & Output
4
2
2 1
3
1 2 1
4
2 4 1 3
5
2 5 1 4 3

1
1 2 1
1
1 3 2
3
2 4 1
2 3 1
1 3 2
4
2 4 2
1 5 3
1 2 1
1 3 1
*/


#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;

    // loop for t test cases
    for (int i = 0; i < t; i++)
    {
        // Input data of length n
        int n, temp;
        vector<int> v;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }

        // Sort
        int l, r, d;
        for (int j = 0; j < n; j++)
        {
            int max = 0, min = n;
            for (int k = j; k < n; k++)
            {
                if (v[k] >= max)
                {
                    max = v[k];
                    l = k;
                } else if (v[k] <= min)
                {
                    min = v[k];
                    r = k;
                }
                d = r - l;
            }

            if (l > r)
            {
                vector<int> v2;
                // need more codes ……

                cout << l << ' ' << r << ' ' << d << endl;
            }
        }

    return 0;
}