#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }
        return PreInCreate(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1);
    }

    TreeNode *PreInCreate(vector<int> &preoder, int preL, int preR,
                          vector<int> &inorder, int inL, int inR)
    {
        // 创建根节点.
        TreeNode *root = new TreeNode(preoder[preL]);

        // 在中序遍历序列中找到根节点的位置.
        int rootPos = inL;
        while (inorder[rootPos] != root->val)
        {
            ++rootPos;
        }

        // 左子树的长度.
        int lchildLen = rootPos - inL;

        // 右子树的长度.
        int rchildLen = inR - rootPos;

        // 如果左子树不为空.
        if (lchildLen > 0)
        {
            root->left = PreInCreate(preoder, preL + 1, preL + lchildLen,
                                     inorder, inL, inL + lchildLen - 1);
        }
        else
        {
            root->left = nullptr;
        }

        // 如果右子树不为空.
        if (rchildLen > 0)
        {
            root->right = PreInCreate(preoder, preR - rchildLen + 1, preR,
                                      inorder, inR - rchildLen + 1, inR);
        }
        else
        {
            root->right = nullptr;
        }

        return root;
    }
};
