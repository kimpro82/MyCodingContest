// LeetCode / Biweekly Contest 181
// 2026.04.25
// Q2. Compare Sums of Bitonic Parts

// #include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

class Solution
{
    public: int compareBitonicSums(vector<int>& nums)
    {
        ll ascendingSum = 0;
        ll descendingSum = 0;
        bool descending = false;
        ll peakNum = 0;

        ascendingSum += nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i-1])
            {
                if (peakNum == 0) peakNum = nums[i-1];
                descending = true;
            }
            if (!descending) ascendingSum += nums[i];
            else descendingSum += nums[i];
        }
        descendingSum += peakNum;

        // cout << ascendingSum << ' ' << descendingSum << ' ' << peakNum << endl;
        
        if (ascendingSum > descendingSum) return 0;
        else if (ascendingSum < descendingSum) return 1;
        else return -1;
    }
};
