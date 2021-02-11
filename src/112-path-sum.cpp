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
    bool flag = false;

public:
    void dfs(TreeNode *root, int rest)
    {
        if (root != nullptr)
        {
            // 选择这个结点.
            rest -= root->val;

            // 找到了满足的条件的路径且路径结尾是叶结点.
            if (rest == 0 && root->left == nullptr && root->right == nullptr)
            {
                flag = true;
                return;
            }

            // 递归遍历左右子.
            dfs(root->left, rest);
            dfs(root->right, rest);

            // 撤销选择.
            rest += root->val;
        }
        else
        {
            return;
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);

        return flag;
    }
};

int main()
{
    TreeNode *node = new TreeNode();

    Solution S;
    S.hasPathSum(node, 4);

    return 0;
}