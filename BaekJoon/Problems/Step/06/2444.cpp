// 2444. 별 찍기 - 7
// 2023.06.19

/* Sample input & output data
5

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            if (i < n)
            {
                if (j < n-i-1) std::cout << ' ';
                else if (j < n+i) std::cout << '*';
                else continue;
            }
            else
            {
                if (j < i-n+1) std::cout << ' ';
                else if (j < (2*n-1) -(i-n+1)) std::cout << '*';
                else continue;
                // 머리로 생각하지 말고, 손으로 그리고 식을 쓰고 계산하자.
            }
        }
        std::cout << '\n';
    }

    return 0;
}