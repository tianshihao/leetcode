#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        // 装填转移方程为 dp[i] = max(dp[i-2] + nums[i], dp[i-1]).
        // 使用滚动数组, first 存储 dp[i-2], second 存储 dp[i-1].
        int first = nums[0];
        int second = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }

        return second;
    }
};