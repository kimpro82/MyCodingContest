// 1920 : (재귀함수) 2진수 변환
// 2023.10.16


#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;


vector<int> v {};

void Recursion(int n)
{
    v.push_back(n % 2);

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
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    cout << endl;

    return 0;
}

// 이 문제는 for사용할 수 없습니다!
