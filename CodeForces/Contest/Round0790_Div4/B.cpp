// Codeforces Round #790 (Div. 4)
// 2022.05.10 23:45, 2 hrs

// B. Equal Candies

/* Sample Input & Output
5
5
1 2 3 4 5
6
1000 1000 5 1000 1000 1000
10
1 2 3 5 1 2 7 9 13 5
3
8 8 8
1
10000000

10
4975
38
0
0
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
 
        vector<int> a;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        
        // Solve
        // 1) find the minimum value
        int min = 10000000;
        for (int j = 0; j < n; j++) if (a[j] < min) min = a[j];
        // 2) get sum of a[j] - min
        int sum = 0;
        for (int j = 0; j < n; j++) sum += a[j] - min;

        // Output
        cout << sum << endl;

    }

    return 0;
}