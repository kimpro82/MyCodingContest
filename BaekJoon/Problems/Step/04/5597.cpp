// 5597. 未提出者は誰だ (과제 안 내신 분..?)
// 2023.06.18

/* Sample input & output data
3
1
4
5
……

2
8
*/

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main()
{
    // Declare & Input
    vector<int> arr(31, 0);
    int n;
    for (int i = 0; i < 28; i++)
    {
        std::cin >> n;
        arr[n] = 1;
    }

    // Output
    for (int i = 1; i < 31; i++) if (arr[i] == 0) std::cout << i << endl;

    return 0;
}
