#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    void dfs(vector<int> &nums, int rest, int ind)
    {
        if (rest < 0)
        {
            return;
        }
        if (rest == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        // 结束条件.
        if (ind == nums.size())
        {
            return;
        }

        // 跳过第 ind 个数, 并进入下一层.
        dfs(nums, rest, ind + 1);

        // 选择第 ind 个数
        tmp.emplace_back(nums[ind]);

        // 进入下一层.
        // 注意每一个可以无限选择.
        dfs(nums, rest - nums[ind], ind);

        // 撤销选择.
        tmp.pop_back();
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        dfs(nums, target, 0);

        return ans.size() * 2 - 1;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution S;
    S.combinationSum4(nums, 4);

    return 0;
}
