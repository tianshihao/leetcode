#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    void dfs(int n, int k, int depth)
    {
        if (tmp.size() + (n - depth + 1) < k)
        {
            return;
        }

        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }

        // 选择.
        tmp.push_back(depth);

        // 不选择.
        dfs(n, k, depth + 1);

        // 撤销选择.
        tmp.pop_back();

        dfs(n, k, depth + 1);
    }

    vector<vector<int>> combine(int n, int k)
    {

        dfs(n, k, 1);

        return ans;
    }
};
