// 9506. Federation Favorites(약수들의 합)
// 2023.07.02

/* Sample input & output data
6
12
28
-1

6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
*/


#include <iostream>
#include <vector>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    while (true)
    {
        // Input
        int n;
        cin >> n;
        if (n == -1) break;

        // Operate
        vector<int> v;
        int sum = 0;
        for (int i = 1; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                sum += i;
            }

            if (n < sum) break;
        }

        // Output
        if (sum == n)
        {
            cout << n << " = 1";
            for (int i = 1; i < v.size(); i++) cout << " + " << v[i];
        }
        else cout << n << " is NOT perfect.";
        cout << endl;
    }

    return 0;
}
