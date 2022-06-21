// 13305. 주유소

/* Sample input & output data
4
2 3 1
5 2 4 1

18

4
3 3 4
1 1 1 1

10
*/


#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
using ll = long long;

int main()
{
    // Input data
    int n;
    cin >> n;

    vector<ll> distance;
    ll temp;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        distance.push_back(temp);
    }

    vector<ll> price;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        price.push_back(temp);
    }
    

    // Calculate the minimum cost
    ll cost = 0, minPrice = price[0];
    for(int i = 0; i < n - 1; i++)
    {
        if (price[i] < minPrice) minPrice = price[i];
        cost += distance[i] * minPrice;

        // test
        // cout << i << ' ' << distance[i] << ' ' << price[i] << ' ' << minPrice << ' ' << cost << endl;
    }

    // Output
    cout << cost << endl;

    return 0;
}