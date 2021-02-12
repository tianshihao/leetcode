#include <cstring>
#include <string>
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
    void dfs(TreeNode *root, vector<string> &ans, string path)
    {
        if (root != nullptr)
        {
            path += to_string(root->val);

            if (root->left == nullptr && root->right == nullptr)
            {
                ans.emplace_back(path);
                return;
            }
            else
            {
                path += "->";
                dfs(root->left, ans, path);
                dfs(root->right, ans, path);
            }
        }
        else
        {
            return;
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;

        dfs(root, ans, "");

        return ans;
    }
};