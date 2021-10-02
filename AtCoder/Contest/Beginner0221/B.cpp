// AtCoder Beginner Contest 221
// 2021-10-02(Sat) 21:00 - 22:40, 100 minutes

// B - typo

/* Sample Input & Output
abc
acb
Yes

aabb
bbaa
No

abcde
abcde
Yes
*/


#include <iostream>

#define endl '\n'

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int len = S.length(), count = 0;
    bool continuous = false;
    string answer = "Yes";

    // Loop that stops when "No" case occurs
    for (int i = 0; i < len; i++)
    {
        if (S[i] != T[i])
        {
            count++;

            if (count == 2)
            {
                if (continuous == false)
                {
                    answer = "No";
                    break;
                }
                else if (!(S[i-1] == T[i] && T[i-1] == S[i]))
                {
                    answer = "No";
                    break;
                }
            }
            else if (count >= 3)
            {
                answer = "No";
                break;
            }

            continuous = true;
        }
        else continuous = false;

        // test
        // cout << i << ' ' << S[i] << ' ' << T[i] << ' ' << count << ' ' << continuous << endl;
    }

    // If "No" case doesn't have ever occurred
    if (count == 1) answer = "No";
    cout << answer << endl;

    return 0;
}