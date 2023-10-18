// 1920 : (재귀함수) 2진수 변환 - Trial 2
// 2023.10.16


#include <iostream>

#define endl '\n'

using namespace std;


string str = "";

void Recursion(int n)
{
    str = to_string(n % 2) + str;

    if (n < 2)
        return;
    else
        Recursion(n / 2);
}

int main()
{
    int n;
    cin >> n;

    Recursion(n);
    cout << str << endl;

    return 0;
}
