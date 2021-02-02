#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void BackTrack(vector<int> &nums, int pos)
    {
        // 结束条件.
        if (pos == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // 选择 nums[i].
        temp.push_back(nums[pos]);
        // 递归进入下一层.
        BackTrack(nums, pos + 1);
        // 撤销选择.
        temp.pop_back();
        // 不选择 nums[i].
        BackTrack(nums, pos + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        BackTrack(nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution S;
    S.subsets(nums);

    return 0;
}
