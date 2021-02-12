#include <climits>
#include <limits>
#include <stack>
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
    bool isValidBST(TreeNode *root)
    {
        // 栈.
        stack<TreeNode *> stack;

        // 工作指针.
        TreeNode *node = root;

        // 最快
        // long long preValue = static_cast<long long>(INT_MIN) - 1;

        // 其它好几种写法.
        // long long preValue = LLONG_MIN;
        // long preValue = LONG_MIN;
        // long preValue = static_cast<long>(numeric_limits<int>::min()) - 1;
        long preValue = numeric_limits<long>::min();

        while (node != nullptr || !stack.empty())
        {
            if (node != nullptr)
            {
                stack.push(node);
                node = node->left;
            }
            else
            {
                node = stack.top();
                stack.pop();

                // node 指向子树的左子.
                if (node->val <= preValue)
                {
                    return false;
                }

                // 更新前一个结点值.
                preValue = node->val;

                // 工作指针指向右.
                node = node->right;
            }
        }

        return true;
    }
};