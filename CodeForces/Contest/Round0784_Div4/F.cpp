// Codeforces Round #784 (Div. 4)
// 2022.04.21 23:35, 2 hrs

// F. Eating Candies

/* Sample Input & Output
4
3
10 20 10
6
2 1 4 2 4 1
5
1 2 4 8 16
9
7 3 20 5 15 1 11 8 10

2
6
0
7
*/


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        // Input data
        int n;
        cin >> n;

        vector<int> w;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            w.push_back(temp);
        }

        // Solve
        int alice = 0, bob = 0, count = 0;
        for (int j = 0; j < n; j++)
        {
            if (alice < bob) alice++;
            if (alice > bob) bob += w[n-j-1];
        }

        // Output
        cout << count << endl;
    }

    return 0;
}