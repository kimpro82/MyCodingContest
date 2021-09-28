// Codeforces Round #744 (Div. 3)
// 2021.09.28 23:35, 2.25 hrs

// E1. Permutation Minimization by Deque

// In fact, the problems E1 and E2 do not have much in common. You should probably think of them as two separate problems.

/* Sample Input & Output
5
4
3 1 2 4
3
3 2 1
3
3 1 2
2
1 2
2
2 1

1 3 2 4 
1 2 3 
1 3 2 
1 2 
1 2 
*/


#include <iostream>
#include <list>

using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;

    // loop for t test cases
    for (int i = 0; i < t; i++)
    {
        // Input data and rearrage lexicographically
        int n, temp;
        list<int> l;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (j == 0) l.push_back(temp);
            else if (temp <= *l.begin()) l.push_front(temp);
            else l.push_back(temp);
        }

        // Output
        for (auto it = l.begin(); it != l.end(); it++) cout << *it << ' ';
        cout << endl;
    }

    return 0;
}