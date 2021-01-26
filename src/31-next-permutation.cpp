#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 从右到左找到第一个较小的数, 找到第一个升序.
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        // 如果逆序存在执行一下语句, 否则说明当前序列已经是一个降序序列, 即最大
        // 的序列, 直接跳过以下步骤, 反转序列即可得到最大序列.
        if (i >= 0)
        {
            // 则再从右到左找到第一个较大的数, 第一个大于 nums[i] 的数.
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j])
            {
                j--;
            }

            // 然后交换 nums[i] 和 nums[j].
            swap(nums[i], nums[j]);
        }

        // 交换之后, 需要将较大的数之后的数重置为升序, 升序排列就是最小序列,
        // 保证交换得到的序列与当前序列紧密排列.
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution S;
    S.nextPermutation(nums);

    return 0;
}
