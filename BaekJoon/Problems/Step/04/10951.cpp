/* Sample input & output data
1 1
2 3
3 4
9 8
5 2

2 5 7 17 7 (vertically)
*/

// BOJ Guide : 입력이 끝날 때까지 A+B를 출력하는 문제. EOF에 대해 알아 보세요.

#include <iostream>

using namespace std;

int main()
{
    int a, b;

    while (true)
    {

        cin >> a >> b;              // wrong when this line is located after cin.eof()
        if (cin.eof() == true)      // find if the input data finish (EOF; End Of File)
        {
            break;
        } else
        {
            cout << a + b << endl;            
        }
    }

    return 0;
}