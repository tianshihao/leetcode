#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto e : nums)
            ret ^= e;
        return ret;
    }
};

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution S;
    S.singleNumber(nums);

    return 0;
}
