#include <algorithm>
#include <unordered_map>
using namespace std;

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
    // select 表示选中结点时, 结点子树上被选择结点的最大权值和.
    // drop 表示不选中结点时, 结点字数上被选择结点的最大权值和.
    unordered_map<TreeNode *, int> select, drop;

public:
    void dfs(TreeNode *node)
    {
        if (node != nullptr)
        {
            dfs(node->left);
            dfs(node->right);

            // 状态转移方程.

            // 当 node 被选中时, node 的左右子都不能被选择, 故 node 被选中的
            // 情况下, 子树被选中结点的最大权值和为 drop[left] + drop[right].
            select[node] = node->val + drop[node->left] + drop[node->right];

            // 当 node 为被选中时, node 的左右子可以被选中, 也可以不被选中.
            // 对于其左右子, 它对 node 的贡献是被选中和不被选中情况下权值
            // 的较大值.
            drop[node] = max(select[node->left], drop[node->left]) +
                         max(select[node->right], drop[node->right]);
        }
    }
    int rob(TreeNode *root)
    {
        dfs(root);

        return max(select[root], drop[root]);
    }
};
