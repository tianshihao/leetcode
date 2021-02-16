#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
private:
    // 存储有向图.
    vector<vector<int>> edges;
    // 标记每个结点的状态, 0: 未搜索, 1: 搜索中, 2: 已完成.
    vector<int> visited;
    // 状态变量, 判断图中是否有环.
    bool valid = true;
    // 用数组模拟栈. 索引 0 为栈底, 索引 1 为栈顶.
    vector<int> ans;

public:
    void dfs(int u)
    {
        // 访问结点 u, 将结点 u 的状态置为搜索中.
        visited[u] = 1;

        // 沿着结点 u 向下搜索.
        for (auto v : edges[u])
        {
            // 状态 0 表示结点 v 未搜索过, 开始搜索结点 v.
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            // 状态 1 表示结点 v 的状态也是搜索中, 处于搜索中的结点 u 找到了
            // 另一个状态处于搜索中的结点, 说明图中有环, 不合法.
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }

        // 状态 2 表示结点 u 完成遍历.
        visited[u] = 2;
        // 将结点 u 入栈.
        ans.push_back(u);

        return;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);

        // 初始化图.
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }

        if (!valid)
        {
            return {};
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{1, 0}};

    Solution S;
    S.findOrder(2, prerequisites);

    return 0;
}
