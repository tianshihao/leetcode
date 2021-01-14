#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }

        return 0;
    }
};

class Solution2
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto num : nums)
        {
            int sz = s.size();
            s.insert(num);
            if (sz == s.size())
            {
                return num;
            }
        }
        return 0;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};

    Solution S;

    cout << S.findRepeatNumber(nums) << endl;

    return 0;
}
