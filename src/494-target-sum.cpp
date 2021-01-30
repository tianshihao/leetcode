#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int ans = 0;
    int n; // 数组长度.
    // vector<char> seq; // 记录满足要求的符号序列.

public:
    void DFS(vector<int> &nums, long long S, int pos)
    {
        if (pos == n)
        {
            // 题目要求是等于 S, 这里找的是 -S, 满足要求的序列会将 S 变成 0.
            if (S == 0)
            {
                ++ans;
                // for (auto c : seq)
                // {
                //     cout << c;
                // }
                // cout << endl;
            }
        }
        else
        {
            // 沿着一个方向搜索下去.
            // 相当于第一次填减号, 第二次填加号.
            for (int i = -1; i < 2; i += 2)
            {
                // if (i < 0)
                // {
                //     seq.push_back('-');
                // }
                // else
                // {
                //     seq.push_back('+');
                // }
                DFS(nums, S + i * nums[pos], pos + 1);
                // seq.pop_back();
            }
        }
    }

    int findTargetSumWays(vector<int> &nums, int S)
    {
        // DFS
        // n = nums.size();
        // DFS(nums, S, 0);
        // return ans;

        // dynamic programming
        vector<int> dp(2001);
        // 偏移量. 第 1000 个元素元素代表第 1 个元素.
        const int offset = 1000;

        // 边界条件.
        dp[nums[0] + offset] = 1;
        dp[-nums[0] + offset] += 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            // 二维数组交替.
            vector<int> next(2001);
            for (int sum = -offset; sum <= offset; ++sum)
            {
                // 方案数不能小于零.
                if (dp[sum + offset] > 0)
                {
                    // 加或减第 nums[i] 组成和为 sum +/- nums[i] 的方案数
                    // 取决于已经得到的和 sum 的方案数.
                    next[sum + nums[i] + offset] += dp[sum + offset];
                    next[sum - nums[i] + offset] += dp[sum + offset];
                }
            }
            dp = next;
        }

        return S > offset ? 0 : dp[S + offset];
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};

    Solution S;
    S.findTargetSumWays(nums, 3);

    return 0;
}
