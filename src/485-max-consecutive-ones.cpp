#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
            {
                ++count;
            }
            else
            {
                ans = max(ans, count);
                count = 0;
            }
        }

        ans = max(ans, count);

        return ans;
    }
};

int main()
{
    vector<int> nums = {1};

    Solution S;

    S.findMaxConsecutiveOnes(nums);

    return 0;
}
