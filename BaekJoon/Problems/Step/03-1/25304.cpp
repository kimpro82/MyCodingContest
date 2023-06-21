// 25304. 영수증
// 2023.06.17

/* Sample input & output data
260000
4
20000 5
30000 2
10000 6
5000 8

Yes
*/


#include <iostream>

using ll = long long;

int main()
{
    ll X;
    int N;
    std::cin >> X >> N;

    ll sum = 0;
    int a, b;
    for (int n = 0; n < N; n++)
    {
        std::cin >> a >> b;
        sum += a * b;
    }

    if (X == sum) std::cout << "Yes" << '\n';
    else std::cout << "No" << '\n';

    return 0;
}