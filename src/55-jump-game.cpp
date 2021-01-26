#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n;)
        {
            // 在 i 处能跳到的范围.
            int range = i + nums[i];
            // 该跳能到达的最远距离.
            int maxDist = i + nums[i];
            // 下一跳.
            int nextJump = i;

            if (maxDist >= n - 1)
            {
                return true;
            }

            // 在允许范围内找能跳到更远的位置.
            for (int j = i + 1; j <= range; ++j)
            {
                if (maxDist < j + nums[j])
                {
                    // 更新可到达的最大值和下一跳位置.
                    nextJump = j;
                    maxDist = j + nums[j];
                }
            }

            // 如果找不到比当前更好的, 说明跳不到了.
            if (nextJump == i)
            {
                return false;
            }

            // 更新位置.
            i = nextJump;
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {3, 0, 8, 2, 0, 0, 1};

    Solution S;

    S.canJump(nums);

    return 0;
}