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
#include <set>
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

    // Input & Operate 1 : Find the distances by a set
    vector<int> v;
    set<int> dists;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);

        if (i > 0 ) dists.insert(v[i] - v[i-1]);
    }

    // Operate 2 : Find the GCD in a vector converted from the set
    vector<int> vDists;
    for (auto it = dists.begin(); it != dists.end(); it++) vDists.push_back(*it);
    int gcd = vDists[0];
    for (int i = 1; i < vDists.size(); i++)
    {
        int temp = gcdf(vDists[i], vDists[i-1]);
        if (temp < gcd) gcd = temp;

        #ifdef test
            printf("i:%d temp:%d gcd:%d\n", i, temp, gcd);
        #endif
    }

    // Output : Do not need to use loop
    #ifdef test
        printf("range:%d range/gcd:%d\n", v[v.size()-1] - v[0], (v[v.size()-1] - v[0]) / gcd);
    #endif
    int ans = (v[v.size()-1] - v[0]) / gcd - (v.size() - 1);
    cout << ans << endl;

    return 0;
}
