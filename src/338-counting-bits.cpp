#include <vector>
using namespace std;

class Solution
{
public:
    int countpop(int x)
    {
        int count;
        // 将 x 中的 1 不断反转, 一次反转一个, 至 x 为 0 时, 求得 1 的个数.
        // 注意, 数字 x 的最低位的 1 总是对应着 x - 1 中的 0, 因此,
        // x 和 x - 1 做与运算总是能将 x 中的最低位的 1 变为 0.
        for (count = 0; x != 0; ++count)
        {
            x &= x - 1;
        }
        return count;
    }

    vector<int> countBits(int num)
    {
        vector<int> ans;

        for (int i = 0; i <= num; ++i)
        {
            ans.push_back(countpop(i));
        }

        return ans;
    }
};
