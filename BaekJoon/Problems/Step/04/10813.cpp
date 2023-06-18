// 10813. 공 바꾸기
// 2023.06.18

/* Sample input & output data
5 4
1 2
3 4
1 4
2 2

3 1 4 2 5
*/

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare
    int n, m;
    int i, j;

    // Input & Swap
    std::cin >> n >> m;
    vector<int> arr(n + 1);
    for (int a = 0; a < n + 1; a++) arr[a] = a;
    for (int a = 0; a < m; a++)
    {
        std::cin >> i >> j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Output
    for (int a = 1; a < n + 1; a++) std::cout << arr[a] << ' ';
    std::cout << endl;

    return 0;
}
