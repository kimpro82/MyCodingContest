// [BOJ] 단계별로 풀어보기 > 12. 정렬

// 10989. 수 정렬하기 3

/* Sample input & output data
10
5
2
3
1
4
2
3
5
1
7

1
1
2
2
3
3
4
5
5
7
*/


#include <iostream>
#include <array>

using namespace std;

#define endl '\n'

int main()
{
    // make it faster
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    // Input N
    int N;
    cin >> N;

    // Input an array
    array<int, 10001> arr = {0, };      // memory limit : 8 MB > int(4 byte) * 10,001
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;                    // 3 -> arr[3]++
    }

    // test
    // for (int i = 1; i <= 10000; i++) if (arr[i] > 0) cout << i << ' ' << arr[i] << endl;

    // Output
    for (int i = 1; i <= 10000; i++) for (int j = 0; j < arr[i]; j++) cout << i << endl;

    return 0;
}