struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        // 如果两个结点都为空.
        if (!p && !q)
        {
            return true;
        }
        // 如果一个结点为空, 另一个不为空.
        if (!p || !q)
        {
            return false;
        }

        // 比较结点的值和 p, q 的左右子.
        // 注意 p 的左子和 q 的右子比较,
        // p 的右子和 q 的左子比较.
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};