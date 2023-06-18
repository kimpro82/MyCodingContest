// 10807. 개수 세기
// 2023.06.18

/* Sample input & output data
11
1 4 1 2 4 2 4 2 3 4 4
2

3
*/

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
    // Declare
    int n, v, temp;
    vector<int> arr;

    // Input
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }
    std::cin >> v;

    // Count
    int count = 0;
    for (int i = 0; i < n; i++) if (arr[i] == v) count++;

    // Output
    std::cout << count << endl;

    return 0;
}