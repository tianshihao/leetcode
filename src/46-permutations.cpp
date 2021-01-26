#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
    {
        // 所有的数都填完了.
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        // 维护动态数组, output[first, len-1] 中为没有用过的数字, 循环从其中每次
        // 拿出一个, 填到第 first 个位置, 即交换 output[i] 和 output[first].
        // 交换完成即填写完毕, 回溯填写 first + 1 个位置. 然后撤销本次交换.
        for (int i = first; i < len; ++i)
        {
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution S;

    S.permute(nums);

    return 0;
}
