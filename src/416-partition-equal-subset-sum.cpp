#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());

        // 如果元素和是奇数.
        if (sum & 1)
        {
            return false;
        }

        // 目标.
        int target = sum / 2;

        // 若最大元素大于 target, 则剩余元素之和一定小于 target.
        if (maxNum > target)
        {
            return false;
        }

        // 其中 dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数(可以是 0 个),
        // 是否存在一种选取方案使得被选取的正整数的和等于 j.
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // 边界条件.
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][target];
    }
};
