// 13909. 창문 닫기
// 2023.07.10

/* Sample input & output data
24

4
*/


#include <iostream>
#include <vector>
#include <algorithm>

// #define test
#define endl '\n'

using namespace std;


// Use some similiar algorithm with the sieve of Eratosthenes
void kindOfEratos(int* n, vector<bool>* v)
{
    for (int i = 1; i <= *n; i++)
    {
        for (int j = i; j <= *n; j += i) (*v)[j] = !(*v)[j];
    }
}

int main()
{
    int n;
    cin >> n;

    // Operate 1 : Open and close the windows
    vector<bool> win(n + 1, false);
    kindOfEratos(&n, &win);

    // Operate 2 : Count the opened windows
    int cnt = 0;
    for (auto it = win.begin(); it != win.end(); it++)
    {
        if (*it == true) cnt++;

        #ifdef test
            cout << int(*it) << ' ';
        #endif
    }
    #ifdef test
        cout << endl;
    #endif

    // Output
    cout << cnt << endl;

    return 0;
}

// 메모리 초과
