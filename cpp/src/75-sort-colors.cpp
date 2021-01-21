#include <vector>
using std::vector;

class Solution
{
    void Swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;

        return;
    }

public:
    void sortColors(vector<int> &nums)
    {
        // 设置三个指针, i 之前的元素为红色, k 之后的元素为蓝色, j 指向当前扫描元素.
        int i = 0, j = 0, k = nums.size() - 1;

        while (j <= k)
        {
            switch (nums[j])
            {
            case 0:
                Swap(nums[i], nums[j]);
                ++i;
                ++j;
                break;
            case 1:
                ++j;
                break;
            case 2:
                Swap(nums[j], nums[k]);
                --k;
            }
        }

        return;
    }
};

int main()
{
    vector<int> colors = {2, 0, 2, 1, 1, 0};

    Solution S;
    S.sortColors(colors);

    return 0;
}
