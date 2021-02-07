#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> &tmp, int ind)
    {
        if (ind == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        // 直接跳过该数.
        dfs(candidates, target, ans, tmp, ind + 1);

        // 如果该数可以被选取.
        if (target - candidates[ind] >= 0)
        {
            // 选取这个数.
            tmp.emplace_back(candidates[ind]);
            // 由于每个数可以被无限次的选取, 所以下一层还是 ind.
            dfs(candidates, target - candidates[ind], ans, tmp, ind);
            // 撤销选择.
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(candidates, target, ans, tmp, 0);

        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    Solution S;

    S.combinationSum(nums, target);

    return 0;
}
