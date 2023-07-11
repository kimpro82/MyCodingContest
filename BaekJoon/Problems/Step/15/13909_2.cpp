// 13909. 창문 닫기
// 2023.07.11

/* Sample input & output data
24

4
*/


#include <iostream>
// #include <vector>

// #define test
#define endl '\n'

using namespace std;


// // Use some similiar algorithm with the sieve of Eratosthenes → It causes MLE (2.1B Bit ≒ 262.5 MB)
// void kindOfEratos(int* n, vector<bool>* v)
// {
//     for (int i = 1; i <= *n; i++)
//     {
//         for (int j = i; j <= *n; j += i) (*v)[j] = !(*v)[j];
//     }
// }

int main()
{
    int n;
    cin >> n;

    // // Operate 1 : Open and close the windows            // not needed
    // vector<bool> win(n + 1, false);
    // kindOfEratos(&n, &win);

    // Operate 2 : Count the opened windows
    // int cnt = 0;
    // for (int i = 1; i < win.size(); i++)
    // {
    //     if (win[i] == 1)
    //     {
    //         cnt++;

    //         #ifdef test
    //             cout << i << ' ';                        // 1 4 9 16 ……
    //         #endif
    //     }
    // }
    // #ifdef test
    //     cout << endl;
    // #endif

    int cnt = 0, i = 1;
    while (i * i <= n)
    {
        cnt++;
        i++;
    }

    // Output
    cout << cnt << endl;

    return 0;
}

// 맞았습니다!!
