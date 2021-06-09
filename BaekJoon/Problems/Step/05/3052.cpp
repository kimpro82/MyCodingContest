/* Sample input & output data
39
40
41
42
43
44
82
83
84
85

6
*/

// modulo : 나머지
// distinct number : 서로 다른 숫자 ≒ 중복되지 않는 숫자

#include <iostream>
#include <set>

using namespace std;

int main()
{
    const int length = 10;
    int input[length];
    set<int> modulo;

    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        modulo.insert(input[i] % 42);
    }

    cout << modulo.size() << endl;

    return 0;
}