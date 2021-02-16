#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u)
    {
        // 访问结点 u, 将结点 u 的状态置为搜索中.
        visited[u] = 1;

        // 沿着结点 u 向下搜索.
        for (int v : edges[u])
        {
            // 状态 0 表示结点 v 未搜索, 开始搜索结点 v.
            if (visited[v] == 0)
            {
                dfs(v);
                // 搜索完结点 v 之后回溯到结点 u.
                if (!valid)
                {
                    return;
                }
            }
            // 状态 1 表示结点 v 也在搜索中, 处于搜索中的 u 找到了另一个
            // 处于搜索中状态的结点, 表示有环, 不合法.
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }

        // 状态 2 表示结点 u 以完成遍历.
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);

        // 初始化图.
        for (const auto &info : prerequisites)
        {
            edges[info[0]].push_back(info[1]);
        }

        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }

        return valid;
    }
};

int main()
{
    vector<vector<int>> prerequistires = {{1, 0}, {0, 1}};

    Solution S;
    S.canFinish(2, prerequistires);

    return 0;
}
