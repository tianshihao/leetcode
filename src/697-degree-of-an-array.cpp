#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> map;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (map.find(nums[i]) == map.end())
            {
                // 建立新的键值对.
                map[nums[i]] = {1, i, i};
            }
            else
            {
                // 计数加 1.
                ++map[nums[i]][0];
                // 更新最后出现的位置.
                map[nums[i]][2] = i;
            }
        }

        int maxDegree = 0, minLen = 0;
        for (auto &[_, vec] : map)
        {
            // 如果当前度大于最大度.
            if (maxDegree < vec[0])
            {
                // 更新最大度.
                maxDegree = vec[0];
                // 并并更新长度.
                minLen = vec[2] - vec[1] + 1;
            }
            // 遇到度相同的元素.
            else if (maxDegree == vec[0])
            {
                // 检查自数组长度是否需要更新.
                if (minLen > vec[2] - vec[1] + 1)
                {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }

        return minLen;
    }
};
