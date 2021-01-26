#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (target <= nums[i])
            {
                return i;
            }
        }
        return nums.size();
    }
};

class Solution2
{
public:
    // 折半查找
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1, result = n;
        while (left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid])
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
