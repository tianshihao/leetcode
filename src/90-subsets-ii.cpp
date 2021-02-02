#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void BackTrack(vector<int> &nums, int pos, vector<int> &path, vector<vector<int>> &ans)
    {
        ans.push_back(path);

        for (int i = pos; i < nums.size(); ++i)
        {
            // 去重.
            if (i > pos && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 选择 nums[i].
            path.push_back(nums[i]);
            // 递归进入下一层.
            BackTrack(nums, i + 1, path, ans);
            // 撤销选择.
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 为了保证剪枝成功, 向量一定要是有序的.
        sort(nums.begin(), nums.end());

        vector<int> path;
        vector<vector<int>> ans;

        BackTrack(nums, 0, path, ans);

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2};

    Solution S;

    vector<vector<int>> ans;

    ans = S.subsetsWithDup(nums);

    return 0;
}
