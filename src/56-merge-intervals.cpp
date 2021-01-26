#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i)
        {
            int L = intervals[i][0], R = intervals[i][1];
            // 如果已合并的结果为空, 或者前一个区间和待放入区间不相交.
            if (!merged.size() || merged.back()[1] < L)
            {
                merged.push_back({L, R});
            }
            // 已合并的最后一个区间的右边界小于待放入区间的左边界, 则区间重合.
            // 而区间已经根据左边界排过序, 所以结果的最后一个元素的左边界
            // 一定小于等于待放入区间左边界, 无需讨论, 只需找到这两个区间
            // 那个有边界大, 更新右边界即可.
            else
            {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

int main()
{
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}};

    Solution S;

    S.merge(intervals);

    return 0;
}
