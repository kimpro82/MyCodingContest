// LeetCode / Biweekly Contest 181
// 2026.04.25
// Q1. Valid Digit Number

#include <string>

using namespace std;

class Solution 
{
    public: bool validDigit(int n, int x) 
    {
        string strN = to_string(n);
        char charX = x + '0';
        bool ans = false;

        if (strN[0] == charX) return false;
        for (int i = 0; i < strN.length(); i++)
        {
            if (strN[i] == charX) return true;
        }

        return false;
    }
};
