﻿#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
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
    int dfs(TreeNode *root, int rest)
    {
        if (root != nullptr)
        {
            // 选择该结点.
            rest -= root->val;

            // 结束条件.

            // 注意, 树中的结点有负值, 所以在以一个结点为结尾的路径后面仍有可能
            // 出现和为 0 的路径, 这样的话, 答案不唯一. 例如,
            // 1 -> -2 = -1
            // 1 -> -2 -> 1 -> -1 = -1
            if (rest == 0)
            {
                return 1 + dfs(root->left, rest) +
                       dfs(root->right, rest);
            }
            else
            {
                // 递归遍历左右子.
                return dfs(root->left, rest) +
                       dfs(root->right, rest);
            }
        }
        // 找到了叶结点也没有找到合适的路径.
        else
        {
            return 0;
        }
    }

    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int ans = 0;

        // 层序遍历. 用队列存储结点.
        queue<TreeNode *> que;
        que.push(root);

        // 层序遍历.
        while (!que.empty())
        {
            int size = que.size();
            while (size > 0)
            {
                // 取队首元素.
                TreeNode *cur = que.front();
                que.pop();

                ans += dfs(cur, sum);

                if (cur->left)
                {
                    que.push(cur->left);
                }
                if (cur->right)
                {
                    que.push(cur->right);
                }

                --size;
            }
        }

        return ans;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);

        int ret = Solution().pathSum(root, sum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}