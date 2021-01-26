#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // 插入区间左端点.
        int left = newInterval[0];
        // 插入区间右端点.
        int right = newInterval[1];

        vector<vector<int>> ans;
        // 标记插入区间是否被插入.
        bool flag = false;

        // 考察每一个区间
        for (auto &interval : intervals)
        {
            // 区间左端点大于插入区间的右端点, 说明没有交集. 无法合并, 将其加入答案.
            if (interval[0] > right)
            {
                // 插入区间可以放置进来.
                if (!flag)
                {
                    ans.push_back({left, right});
                    flag = true;
                }
                ans.push_back(interval);
            }
            // 区间右端点小于插入区间的左端点, 说明也没有交集.
            else if (interval[1] < left)
            {
                ans.push_back(interval);
            }
            // 否则就是有交集. 计算并集
            else
            {
                // 相当于更新插入区间.
                left = min(interval[0], left);
                right = max(interval[1], right);
            }
        }
        // 如果最后都没有被插入的话, 将插入区间插入.
        if (!flag)
        {
            ans.push_back({left, right});
        }

        return ans;
    }
};
