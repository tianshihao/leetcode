#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> freq;

public:
    void
    dfs(vector<int> &candidates, int rest, vector<vector<int>> &ans, vector<int> &tmp, int ind)
    {
        if (rest == 0)
        {
            ans.emplace_back(tmp);
            return;
        }
        if (ind == candidates.size())
        {
            return;
        }

        // 跳过当前数字.
        dfs(candidates, rest, ans, tmp, ind + freq[candidates[ind]]);

        // 计算当前数字能被选的最大次数.
        int most = min(rest / candidates[ind], freq[candidates[ind]]);

        // 将数字 candidates[ind] 选择 most 次.
        // 每次执行一次回溯. 回溯也要跳过该数字.
        for (int i = 1; i <= most; ++i)
        {
            tmp.emplace_back(candidates[ind]);
            dfs(candidates, rest - i * candidates[ind], ans, tmp, ind + freq[candidates[ind]]);
        }
        // 撤销选择.
        for (int i = 1; i <= most; ++i)
        {
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        for (int num : candidates)
        {
            // 没有以 num 为键的键值对.
            if (freq.find(num) == freq.end())
            {
                freq.insert(make_pair(num, 1));
            }
            else
            {
                ++freq[num];
            }
        }

        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(candidates, target, ans, tmp, 0);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;

    Solution S;
    S.combinationSum2(candidates, target);

    return 0;
}
