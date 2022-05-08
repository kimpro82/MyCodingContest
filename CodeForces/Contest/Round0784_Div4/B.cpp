// Codeforces Round #784 (Div. 4)
// 2022.04.21 23:35, 2 hrs

// B. Triple

/* Sample Input & Output
7
1
1
3
2 2 2
7
2 2 3 3 4 2 2
8
1 4 3 4 3 2 4 1
9
1 1 1 2 2 2 3 3 3
5
1 5 2 4 3
4
4 4 4 4

-1
2
2
4
3
-1
4
*/


#include <iostream>
#include <vector>
// #include <map>                               // using .insert() frequently in map requires too many times
#include <array>                                // better than <map>

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
        array<int, 200001> arr = {0, };         // 2 * 10^5 is not 20,000!
        int ans = -1;
        for (int j = 0; j < n; j++)
        {
            arr[a[j]]++;

            if (arr[a[j]] >= 3)
            {
                ans = a[j];
                break;
            }
        }

        // Output
        cout << ans << endl;
    }

    return 0;
}