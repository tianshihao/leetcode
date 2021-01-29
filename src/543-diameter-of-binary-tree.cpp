#include <algorithm>
#include <iostream>
#include <memory>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    int ans;

public:
    int depth(TreeNode *root)
    {
        // 访问到空结点, 返回 0.
        if (root == nullptr)
        {
            return 0;
        }

        // 计算以左子为根的子树的深度.
        int leftDepth = depth(root->left); // 左儿子为根的子树的深度
        // 计算以右子为根的子树的深度.
        int rightDepth = depth(root->right);
        // 计算 leftDepth + rightDepth 并更新 ans.
        ans = std::max(ans, leftDepth + rightDepth);
        // 返回以该结点为根的子树的深度.
        return std::max(leftDepth, rightDepth) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;

        // 左子的最大深度等于左边的最大路径数, 右子同理, 二者相加即为某根结点
        // 的最大路径长度.
        // 递归计算每一个结点的左右子深度, 从而得到每个结点的左右子路径之和,
        // 即直径.
        // 最后函数返回该以该结点为根的子树的深度.
        depth(root);

        return ans;
    }
};

int main()
{
    std::unique_ptr<TreeNode> fifth(new TreeNode(5));
    fifth->left = nullptr;
    fifth->right = nullptr;
    std::unique_ptr<TreeNode> fourth(new TreeNode(4));
    fourth->left = nullptr;
    fourth->right = nullptr;
    std::unique_ptr<TreeNode> third(new TreeNode(3));
    third->left = nullptr;
    third->right = nullptr;
    std::unique_ptr<TreeNode> second(new TreeNode(2));
    second->left = fourth.get();
    second->right = fifth.get();
    std::unique_ptr<TreeNode> root(new TreeNode(1));
    root->left = second.get();
    root->right = third.get();

    Solution S;

    std::cout << S.diameterOfBinaryTree(root.get());

    return 0;
}
