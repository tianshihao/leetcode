#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return {};
        }

        int n = nums.size();
        vector<int> ans(n - k + 1);
        int left = 0, right = 0;
        int idx = 0;
        // 维护一个最大值队列, 队首保存窗口最大值, 且非严格单调递减.
        deque<int> que;

        while (right < n)
        {
            // ! que 内仅包含窗口内的元素, 每轮窗口移动移除元素 nums[left - 1].
            if (left > 0 && que[0] == nums[left - 1])
            {
                // 移除过期的最大值.
                que.pop_front();
            }

            // 维护一个非严格单调递减队列.
            while (!que.empty() &&
                   que.size() <= k &&
                   que.back() < nums[right])
            {
                // 将小于 nums[right] 的元素移除.
                que.pop_back();
            }

            // 添加新元素 nums[right] 到合适的位置.
            que.push_back(nums[right]);

            if (right - left + 1 == k)
            {
                // 将窗口最大值加入答案.
                ans[idx++] = que.front();

                // 左指针右移.
                ++left;
            }

            // 右指针右移.
            ++right;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {9, 10, 9, -7, -4, -8, 2, -6};

    Solution S;
    S.maxSlidingWindow(nums, 5);

    return 0;
}
