#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return {};
        }
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        // 枚举 a
        for (int first = 0; first < n; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }

            // 更新目标值.
            int newTarget = target - nums[first];

            // 枚举 b, 转化为三数问题.
            for (int second = first + 1; second < n; ++second)
            {
                // 需要和上一次枚举的数不相同.
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }

                // d 对应的指针初始指向数组的最右端.
                int fourth = n - 1;
                // 更新目标指.
                int newTarget2 = newTarget - nums[second];
                // 枚举 c
                for (int third = second + 1; third < n; ++third)
                {
                    // 需要和上一次枚举的数不相同.
                    if (third > second + 1 && nums[third] == nums[third - 1])
                    {
                        continue;
                    }
                    // 保证 c 的指针在 d 的指针的左侧
                    while (third < fourth && nums[third] + nums[fourth] > newTarget2)
                    {
                        --fourth;
                    }
                    // 如果指针重合, 不会有 b + c + d = target - a 了.
                    if (third == fourth)
                    {
                        break;
                    }
                    if (nums[third] + nums[fourth] == newTarget2)
                    {
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};

    Solution S;

    vector<vector<int>> ans = S.fourSum(nums, 0);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i][0] << ", " << ans[i][1] << ", " << ans[i][2] << ", " << ans[i][3] << endl;
    }

    return 0;
}