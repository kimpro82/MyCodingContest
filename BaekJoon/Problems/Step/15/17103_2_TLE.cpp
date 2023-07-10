// 17103. 골드바흐 파티션
// 2023.07.10

/* Sample input & output data
5
6
8
10
12
100

1
1
2
1
6
*/


#include <iostream>
#include <set>
#include <cmath>

#define test
#define endl '\n'

using namespace std;


void getPn(set<int>* pn)
{
    for (int i = 2; i < 1000000; i++)
    {
        bool aIsPrime = true;
        for (int j = 2; j <= int(sqrt(i)); j++)
        {
            if (i % j == 0)
            {
                aIsPrime = false;
                break;
            }
        }

        if (aIsPrime == true) (*pn).insert(i);
    }
}

int main()
{
    // First, get a set of prime numbers between 2 and 1m
    set<int> pn;
    getPn(&pn);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        // Count when `j` and `j - n` both exist
        int cnt = 0;
        // Trial 1 - 
        for (int j = 2; j <= n / 2; j++)
        {
            if (pn.find(j) != pn.end() && pn.find(n - j) != pn.end()) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}

// 시간 초과
