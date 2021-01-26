#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        queue<TreeNode *> Q;
        Q.push(root);
        vector<vector<int>> ans;

        while (!Q.empty())
        {
            int currentLevelSize = Q.size();
            vector<int> level;
            while (currentLevelSize > 0)
            {
                TreeNode *node = Q.front();
                Q.pop();
                level.emplace_back(node->val);

                if (node->left)
                {
                    Q.push(node->left);
                }
                if (node->right)
                {
                    Q.push(node->right);
                }
                currentLevelSize -= 1;
            }
            ans.emplace_back(level);
        }

        return ans;
    }
};