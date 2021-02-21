#include <deque>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> maxQue, minQue;
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;

        while (right < n)
        {
            // 两个单调队列维护最大值和最小值.
            while (!maxQue.empty() && maxQue.back() < nums[right])
            {
                maxQue.pop_back();
            }
            while (!minQue.empty() && minQue.back() > nums[right])
            {
                minQue.pop_back();
            }

            maxQue.push_back(nums[right]);
            minQue.push_back(nums[right]);

            // 如果最大值和最小值之差超过限制.
            while (!maxQue.empty() && !minQue.empty() &&
                   maxQue.front() - minQue.front() > limit)
            {
                // 删除左指针对应的元素.
                if (nums[left] == maxQue.front())
                {
                    maxQue.pop_front();
                }
                if (nums[left] == minQue.front())
                {
                    minQue.pop_front();
                }
                ++left;
            }

            // 更新答案.
            ans = max(ans, right - left + 1);

            // 右指针
            ++right;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {8, 2, 4, 7};

    Solution S;
    S.longestSubarray(nums, 4);

    return 0;
}