#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    void dfs(int k, int rest, int ind)
    {
        // 剪枝优化.
        if (rest < 0)
        {
            return;
        }

        // 结束条件.
        if (rest == 0)
        {
            // 组合个数满足题目要求.
            if (tmp.size() == k)
            {
                ans.emplace_back(tmp);
            }
            return;
        }
        // 这个不能没有, 比如当什么都没有选择时, 在此结束搜索.
        if (ind == 10)
        {
            return;
        }

        // 跳过第 ind 个数, 进入下一层.
        dfs(k, rest, ind + 1);

        // 选择第 ind 个数.
        tmp.emplace_back(ind);

        // 进入下一层.
        dfs(k, rest - ind, ind + 1);

        // 撤销选择.
        tmp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        // 注意, 题目要求只含 1 - 9 的正整数, 这里从 1 开始.
        dfs(k, n, 1);

        return ans;
    }
};

int main()
{
    Solution S;
    S.combinationSum3(3, 7);

    return 0;
}
