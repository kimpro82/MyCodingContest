// 2485. 가로수
// 2023.07.10

/* Sample input & output data
4
2
6
12
18

5
*/


#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;


int gcdf(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    int n;
    cin >> n;

    // Input & Operate 1 : Find the shortest distance as GCD
    vector<int> v;
    int gcd, temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);

        if (i == 1 ) gcd = v[1] - v[0];
        else if (i > 1) gcd = gcdf(gcd, v[i] - v[i-1]);

        #ifdef test
            if (i > 0) printf("i:%d gcd:%d\n", i, gcd);
        #endif
    }

    // Operate 2 : Count trees newly planted
    int ans = 0;
    int loc = v[0];
    while (loc < v[n-1])
    {
        loc += gcd;
        if (binary_search(v.begin(), v.end(), loc)) continue;
        else ans++;
    }

    // Output
    cout << ans << endl;

    return 0;
}

// 시간 초과
