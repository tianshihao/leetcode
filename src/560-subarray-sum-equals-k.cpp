#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 存储每个前缀和出现的此处的哈希表.
        unordered_map<int, int> mp;
        // 边界条件, 前缀和为 0 的子序列出现的次数为 1.
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &x : nums)
        {
            // pre 表示当前最新的前缀和.
            pre += x;
            // 从哈希表中寻找符合要求的前缀和.
            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};

    Solution S;
    S.subarraySum(nums, 7);

    return 0;
}
