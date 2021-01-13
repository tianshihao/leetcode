#include <queue>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 广度优先搜索, 层序遍历
        queue<TreeNode *> Q;
        Q.push(root);
        int depth = 0;

        while (!Q.empty())
        {
            int sz = Q.size();
            while (sz > 0)
            {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left)
                {
                    Q.push(node->left);
                }
                if (node->right)
                {
                    Q.push(node->right);
                }
                sz -= 1;
            }
            depth += 1;
        }
        return depth;
    }
};
