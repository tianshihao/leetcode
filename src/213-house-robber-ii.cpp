#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 问题很简单. 以下标从 1 到 n 为例进行说明.
     * 由于在这道题中元素 1 和 n 是相邻的, 互斥, 所以若选择了 1 就不能选择 n,
     * 若选择了 n, 就不能选择 1.
     * 因此, 选择 1 时, 最大能选择的元素为 n-1,
     * 选择 n 时, 最小能选择的元素为 2.
     * 所以, 问题就变成了从元素 1 到 n-1 或者从元素 2 到 n 中选择元素.
     * 而这个问题已经在 198 中解决了, 只需要找到两种情况下的较大值即可.
     */
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
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        // 和 198 一样的滚动数组.

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int ans = 0;

        for (int i = 2; i < n - 1; ++i)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }

        ans = second;

        first = nums[1];
        second = max(nums[1], nums[2]);

        for (int i = 3; i < n; ++i)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }

        return max(ans, second);
    }
};