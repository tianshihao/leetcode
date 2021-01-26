#include <algorithm>
#include <vector>
using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i)
        {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    Solution S;
    S.maxProduct(nums);

    return 0;
}
