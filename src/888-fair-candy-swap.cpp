﻿#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        vector<int> ans;
        unordered_set<int> rec(A.begin(), A.end());

        for (auto &y : B)
        {
            int x = y + delta;
            if (rec.count(x))
            {
                ans = vector<int>({x, y});
                break;
            }
        }

        return ans;
    }
};