#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;

public:
    void dfs(TreeNode *root, int rest)
    {
        if (root != nullptr)
        {
            // 记录结点.
            path.emplace_back(root->val);
            // 选择该结点.
            rest -= root->val;

            // 找到了满足的条件的路径且路径结尾是叶结点.
            if (rest == 0 && root->left == nullptr && root->right == nullptr)
            {
                ans.emplace_back(path);
            }

            // 递归遍历左右子.
            dfs(root->left, rest);
            dfs(root->right, rest);

            // 撤销选择.
            path.pop_back();
        }
        else
        {
            return;
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);

        return ans;
    }
};