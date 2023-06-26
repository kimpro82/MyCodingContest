// [BOJ] 단계별로 풀어보기 > 10. 재귀

// 2447. 별 찍기 - 10

/* Sample input & output data
27

***************************
* ** ** ** ** ** ** ** ** *
***************************
***   ******   ******   ***
* *   * ** *   * ** *   * *
……
*/


#include <iostream>

using namespace std;

#define endl '\n'

char star(int r, int c, int n)
{
    if (n <= 3)
    {
        if (r % 3 == 1 && c % 3 == 1) return ' ';
        else return '*';
    }

    if (r / (n / 3) == 1 && c / (n / 3) == 1) return ' ';

    return star(r % (n / 3), c % (n / 3), n / 3);
}

int main()
{
    int n;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++) cout << star(r, c, n);
        cout << endl;
    }

    return 0;
}