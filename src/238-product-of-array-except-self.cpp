#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @note 时间复杂度 O(n), 空间复杂度 O(n).
     */
    vector<int> anotherMethod(vector<int> &nums)
    {
        int n = nums.size();

        // L 和 R 分别存储左右两侧的乘积列表.
        vector<int> L(n, 0), R(n, 0);

        // 对于索引为 '0' 的元素, 因为左侧没有元素, 所以设置 L[0] = 1.
        L[0] = 1;
        // L[i] 为元素 nums[i] 左侧所有元素的乘积.
        for (int i = 1; i < n; ++i)
        {
            L[i] = L[i - 1] * nums[i - 1];
        }

        // 对于索引为 "n - 1" 的元素, 因为右侧没有元素,
        // 所以设置 R[n - 1] = 1.
        R[n - 1] = 1;
        // R[i] 为元素 nums[i] 右侧所有元素的乘积.
        for (int i = n - 2; i >= 0; --i)
        {
            R[i] = R[i + 1] * nums[i + 1];
        }

        vector<int> ans(n, 0);

        // 对于索引 i, 除了 nums[i] 之外的元素乘积就是左侧所有元素的乘积
        // 乘以右侧所有元素的乘积.
        for (int i = 0; i < n; ++i)
        {
            ans[i] = L[i] * R[i];
        }

        return ans;
    }
    /**
     * @note 时间复杂度 O(n), 空间复杂度 O(1).
     */
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // 使用结果输出数组存储左侧的乘积列表. 减小空间复杂度.
        vector<int> ans(n);
        // 由于元素 nums[0] 左侧没有任何元素, 所以设置 ans[0] = 1.
        ans[0] = 1;
        // 先循环取得左侧乘积列表.
        for (int i = 1; i < n; ++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // 取消右侧乘积列表, 使用一个变量 R 来动态表示某一个位置元素的右侧
        // 所有元素乘积.
        // 由于元素 nums[n - 1] 右侧没有任何元素, 所以设置 R = 1.
        int R = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            // 对于元素 nums[i], 其左侧乘积为 ans[i], 右侧乘积为 R.
            ans[i] *= R;

            // 更新右侧乘积.
            // R 是右侧乘积, 所以更新时只需要使用当前元素值乘到 R 上.
            R *= nums[i];
        }

        return ans;
    }
};