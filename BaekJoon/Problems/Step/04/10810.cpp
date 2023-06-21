// 10810. 공 넣기
// 2023.06.18

/* Sample input & output data
5 4
1 2 3
3 4 4
1 4 1
2 2 2

1 2 1 1 0
*/

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int n, m;
    int i, j, k;

    // Input
    std::cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for (int a = 0; a < m; a++)
    {
        std::cin >> i >> j >> k;
        for (int b = i; b <= j; b++) arr[b] = k;
    }

    // Output
    for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
    std::cout << endl;

    return 0;
}
