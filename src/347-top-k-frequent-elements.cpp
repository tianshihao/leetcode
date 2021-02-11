#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> occurences;
        for (auto &num : nums)
        {
            ++occurences[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);

        for (auto &[num, count] : occurences)
        {
            if (q.size() == k)
            {
                if (q.top().second < count)
                {
                    q.pop();
                    q.emplace(num, count);
                }
            }
            else
            {
                q.emplace(num, count);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}