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
    /**
     * @brief 以后序展开.
     */
    void doFlatten(TreeNode *root)
    {
        if (root != nullptr)
        {
            // 至少存在一子, 才需要展开.
            if (root->left != nullptr || root->right != nullptr)
            {
                // 先展开左子和右子.
                doFlatten(root->left);
                doFlatten(root->right);

                // 后展开根结点.

                // 若左子为空, 则无需展开.
                if (root->left == nullptr)
                {
                    return;
                }

                // 1. 保存原来的右子.
                TreeNode *r = root->right;

                // 2. 将根结点的右子改为左子.
                root->right = root->left;

                // 2. 同时左子置为空.
                root->left = nullptr;

                // 3. 工作指针, 指向根结点.
                TreeNode *p = root;

                // 3. 工作指针找寻新的右子的叶结点.
                while (p->right != nullptr)
                {
                    p = p->right;
                }

                // 3. 将保存的原来的右子链接到新的右子末尾.
                p->right = r;
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    }

    void flatten(TreeNode *root)
    {
        if (root != nullptr)
        {
            doFlatten(root);
        }
        else
        {
            return;
        }
    }
};

int main()
{
    TreeNode *third = new TreeNode(3);
    TreeNode *foutrth = new TreeNode(4);
    TreeNode *second = new TreeNode(2, third, foutrth);

    TreeNode *sixth = new TreeNode(6);
    TreeNode *fifth = new TreeNode(5, nullptr, sixth);

    TreeNode *first = new TreeNode(1, second, fifth);

    TreeNode *c = new TreeNode(3);
    TreeNode *b = new TreeNode(2, c, nullptr);
    TreeNode *a = new TreeNode(1, nullptr, b);

    Solution S;
    // S.flatten(first);
    S.flatten(a);

    return 0;
}
