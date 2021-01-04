﻿#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        // 升序.
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first)
        {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second)
            {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target)
                {
                    // 由于 nums 是升序, 所以大于 target 的情况, 一定要左移右指针.
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third)
                {
                    break;
                }
                if (nums[second] + nums[third] == target)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
                // 如果 nums[second] + nums[third] < target
                // 则进入下一次循环, 左指针右移, ++second.
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution S;

    vector<vector<int>> ans = S.threeSum(nums);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i][0] << ", " << ans[i][1] << ", " << ans[i][2] << endl;
    }

    return 0;
}
