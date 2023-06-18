// 10811. 바구니 뒤집기
// 2023.06.18

/* Sample input & output data
5 4
1 2
3 4
1 4
2 2

3 4 1 2 5
*/

#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int n, m;
    int i, j;

    // Input & Reverse partially
    std::cin >> n >> m;
    vector<int> arr(n + 1);
    for (int a = 0; a < n + 1; a++) arr[a] = a;
    for (int b = 0; b < m; b++)
    {
        std::cin >> i >> j;
        std::reverse(arr.begin() + i, arr.begin() + j + 1);

        // test
        #ifdef test
            for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
            std::cout << endl;
        #endif
    }

    // Output
    for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
    std::cout << endl;

    return 0;
}
