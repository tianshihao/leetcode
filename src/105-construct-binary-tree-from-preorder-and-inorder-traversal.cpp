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
public:
    TreeNode *preInCreate(vector<int> &preOrder, int preL, int preR,
                          vector<int> &inOrder, int inL, int inR)
    {
        // 创建根结点.
        TreeNode *root = new TreeNode();

        // 先序序列的第一个值是根结点的值.
        root->val = preOrder[preL];

        // 中序序列中的根结点索引.
        int inRootInd = inL;

        // 在中序序列中找到根结点的索引.
        while (inOrder[inRootInd] != root->val)
        {
            ++inRootInd;
        }

        // 计算左子长度.
        int lchildLen = inRootInd - inL;
        // 计算右子长度.
        int rchildLen = inR - inRootInd;

        // 如果左子不为空.
        if (lchildLen > 0)
        {
            // 递归创建左子.
            root->left = preInCreate(preOrder, preL + 1, preL + lchildLen,
                                     inOrder, inL, inL + lchildLen - 1);
        }
        else
        {
            root->left = nullptr;
        }

        // 如果右子不为空.
        if (rchildLen > 0)
        {
            // 递归创建右子.
            root->right = preInCreate(preOrder, preR - rchildLen + 1, preR,
                                      inOrder, inR - rchildLen + 1, inR);
        }
        else
        {
            root->right = nullptr;
        }

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (!preorder.empty())
        {
            return preInCreate(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1);
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    vector<int> preOrder = {1, 2, 3};
    vector<int> inOrder = {3, 2, 1};

    Solution S;

    S.buildTree(preOrder, inOrder);

    return 0;
}
