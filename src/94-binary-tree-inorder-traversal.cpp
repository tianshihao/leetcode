#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 初始化栈.
        stack<TreeNode *> s;
        // 工作指针指向根.
        TreeNode *p = root;
        // 存储遍历序列.
        vector<int> ans;

        // 指针不为空或栈非空.
        while (p != nullptr || !s.empty())
        {
            // 指针不空.
            if (p != nullptr)
            {
                // 入栈.
                s.push(p);
                // 指向左.
                p = p->left;
            }
            else
            {
                // 弹栈.
                p = s.top();
                s.pop();
                // 访问.
                ans.emplace_back(p->val);
                // 指向右.
                p = p->right;
            }
        }

        return ans;
    }
};
