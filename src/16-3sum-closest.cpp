#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 最小的差的绝对值.
        int best = 1e7;

        // 根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target))
            {
                best = cur;
            }
        };

        // 枚举 a
        for (int first = 0; first < n; ++first)
        {
            // 保证和上一次枚举的元素不相等
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            // 使用双指针枚举 b 和 c
            int second = first + 1, third = n - 1;
            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                // 如果和为 target 直接返回答案
                if (sum == target)
                {
                    return target;
                }
                update(sum);
                if (sum > target)
                {
                    // 如果和大于 target，移动 c 对应的指针
                    int newThird = third - 1;
                    // 移动到下一个不相等的元素
                    while (second < newThird && nums[newThird] == nums[third])
                    {
                        --newThird;
                    }
                    third = newThird;
                }
                else
                {
                    // 如果和小于 target，移动 b 对应的指针
                    int newSecond = second + 1;
                    // 移动到下一个不相等的元素
                    while (newSecond < third && nums[newSecond] == nums[second])
                    {
                        ++newSecond;
                    }
                    second = newSecond;
                }
            }
        }
        return best;
    }
};

int main()
{
    return 0;
}