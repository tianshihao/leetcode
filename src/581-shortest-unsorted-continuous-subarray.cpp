#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int max = numeric_limits<int>::min();
        int min = numeric_limits<int>::max();
        int n = nums.size();

        // 找到逆序中的最值.
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                max = std::max(max, nums[i - 1]);
                min = std::min(min, nums[i]);
            }
        }

        // 找到逆序的起点和终点.
        int left, right;
        for (left = 0; left < n; ++left)
        {
            if (min < nums[left])
            {
                break;
            }
        }
        for (right = n - 1; right >= 0; --right)
        {
            if (max > nums[right])
            {
                break;
            }
        }

        return right - left < 0 ? 0 : right - left + 1;
    }
};