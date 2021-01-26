#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, maxSum = nums[0];
        for (const auto &x : nums)
        {
            // pre 就是以某个结点为结束点的所有子序列中和中的最大子序列和.
            // pre 的表达式即动态规划的状态转移方程 f(i) = max{f(i), f(i - 1) + ai}.
            pre = max(pre + x, x);
            // maxSum 只是用来记录最大值的变量.
            maxSum = max(maxSum, pre);
        }
        return maxSum;
    }
};

class Solution2
{
public:
    // 状态.
    struct Status
    {
        int lSum; // 表示区间 [l, r] 内以 l 为左端点的最大子段和.
        int rSum; // 表示区间 [l, r] 内以 r 为右端点的最大子段和.
        int iSum; // 表示区间 [l, r] 的区间和.
        int mSum; // 表示区间 [l, r] 最大子段和.
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status){lSum, rSum, iSum, mSum};
    };

    Status get(vector<int> &a, int l, int r)
    {
        if (l == r)
        {
            return (Status){a[l], a[l], a[l], a[l]};
        }

        int m = (l + r) >> 1;

        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);

        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};

int main()
{
    Solution2 S;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << S.maxSubArray(nums) << endl;

    system("pause");

    return 0;
}