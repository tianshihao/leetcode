#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            // 将原数组中的元素取反, 作为 i + 1 出现过的标记.
            if (nums[i] > 0)
            {
                if (nums[abs(nums[i] - 1)] > 0)
                {
                    nums[abs(nums[i] - 1)] *= -1;
                }
            }
            // 不能重复标记.
            else
            {
                if (nums[abs(-nums[i] - 1)] > 0)
                {
                    nums[abs(-nums[i] - 1)] *= -1;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1};

    Solution S;
    S.findDisappearedNumbers(nums);

    return 0;
}
