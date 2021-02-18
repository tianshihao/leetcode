#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    // 并查集结点.
    struct Node
    {
        // 结点值.
        double value;
        // 结点亲结点.
        Node *parent;

        // 构造函数.
        Node() { parent = this; }
        Node(double v) : value(v), parent(this) {}
    };

    // 查找结点的根结点.
    Node *findRoot(Node *node)
    {
        // 若根结点是自身.
        if (node->parent == node)
        {
            // 则返回自身.
            return node;
        }
        // 否则.
        else
        {
            // 递归地寻找.
            return findRoot(node->parent);
        }
    }

    void unionNode(Node *node1, Node *node2, double value, unordered_map<string, Node *> &map)
    {
        // 找到两个结点的根结点.
        Node *root1 = findRoot(node1), *root2 = findRoot(node2);

        //
        double ratio = node2->value * value / node1->value;

        for (auto item : map)
        {
            if (findRoot(item.second) == root1)
            {
                item.second->value *= ratio;
            }
        }

        // 将结点 1 所处集合的根结点指向结点 2 所处集合的根结点.
        root1->parent = root2;
    }

public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // 存储结点的哈希表
        unordered_map<string, Node *> map;

        // 建立树的过程.
        for (int i = 0; i < equations.size(); ++i)
        {
            // 被除数, 充当亲结点.
            string parent = equations[i][0];
            // 除数, 充当子结点.
            string child = equations[i][1];

            auto end = map.end();

            // 亲子结点都不在树中.
            if (map.find(parent) == end && map.find(child) == end)
            {
                // parent / child = values[i].
                map[parent] = new Node(values[i]);
                map[child] = new Node(1.0);
                // 并建立亲子关系.
                map[child]->parent = map[parent];
            }
            // 被除数不在树中, 即亲结点不在树中.
            else if (map.find(parent) == end)
            {
                // parent / child = values[i].
                // parent = child * values[i].
                // 根据子结点的值和亲结点本身的值确定亲结点新的值.
                map[parent] = new Node(values[i] * map[child]->value);
                // 并建立亲子关系.
                map[parent]->parent = map[child];
            }
            // 除数不在树中, 即子结点不在树中.
            else if (map.find(child) == end)
            {
                // parent / child = values[i].
                // child = parent / values[i].
                // 根据存在的亲结点的值确定子结点的值.
                map[child] = new Node(map[parent]->value / values[i]);
                // 并建立亲子关系.
                map[child]->parent = map[parent];
            }
            // 被除数和除数属于两棵树.
            else
            {
                unionNode(map[parent], map[child], values[i], map);
            }
        }

        vector<double> ans;

        for (int i = 0; i < queries.size(); ++i)
        {
            string parent = queries[i][0];
            string child = queries[i][1];

            if (map.find(parent) != map.end() &&
                map.find(child) != map.end() &&
                findRoot(map[parent]) == findRoot(map[child]))
            {
                ans.push_back(map[parent]->value / map[child]->value);
            }
            else
            {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<string>> equations = {
        {"a", "e"},
        {"b", "e"}};

    vector<double> values = {4.0, 3.0};

    vector<vector<string>> queries = {
        {"a", "b"},
        {"e", "e"},
        {"x", "x"}};

    Solution S;
    S.calcEquation(equations, values, queries);

    return 0;
}
