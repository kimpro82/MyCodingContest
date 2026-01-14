// AtCoder Beginner Contest 223
// 2021-10-17(Sun) 21:00 - 22:40, 100 minutes

// B - String Shifting

/* Sample Input & Output
aaba
aaab
baaa

z
z
z

abracadabra
aabracadabr
racadabraab
*/


#include <iostream>
#include <vector>
// #include <queue>
// #include <string>

#define endl '\n'

using namespace std;

int main()
{
    // Input data
    string S;
    cin >> S;
    int size = S.length();

    // Do left shift and determine min and max
    string max = S, min = S;
    for (int i = 0; i < size; i++)
    {
        // Left shift
        char temp = S.front();
        S.erase(0, 1);
        S += temp;

        // Compare
        if (min > S) min = S;
        else if (max < S) max = S;
    }

    // Output
    cout << min << endl;
    cout << max << endl;

    return 0;
}