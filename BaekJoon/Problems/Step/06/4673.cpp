/* Sample output data
1
3
5
……
9993
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    // make a set {1, 2, ……, 9999}
    set<int> mySet;
    for (int i = 1; i < 10000; i++)
    {
        mySet.insert(i);
    }

    // erase digitaditions from mySet{}
    for (int j = 1; j < 10000; j++)
    {
        int digitadition = j;
        if (j > 999)
        {
            digitadition += j / 1000;
        }
        if (j > 99)
        {
            digitadition += (j % 1000) / 100;
        }
        if (j > 9)
        {
            digitadition += (j % 100) / 10;
        }
        digitadition += j % 10;

        // better code?
        // int digitadition = j;
        // if (j > 999)
        // {
        //     digitadition += j / 1000;
        //     digitadition += (j % 1000) / 100;
        //     digitadition += (j % 100) / 10;
        // } else if (j > 99)
        // {
        //     digitadition += (j % 1000) / 100;
        //     digitadition += (j % 100) / 10;
        // } else if (j > 9)
        // {
        //     digitadition += (j % 100) / 10;
        // }
        // digitadition += j % 10;

        mySet.erase(digitadition);
    }

    // output self-numbers
    // make cin/cout faster
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for_each (mySet.begin(), mySet.end(), [](int n)
    {
        cout << n << '\n';
    });

    return 0;
}