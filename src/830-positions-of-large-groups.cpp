#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return {};
        }

        vector<vector<int>> ans;

        int left = 0, right = 0;
        for (left = 0; left < n; ++left)
        {
            for (right = left + 1; right < n; ++right)
            {
                if (s[right] == s[left])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            // 不相等时跳出循环, 此时 right - 1 才是最后一个与 left 指向相同字符的
            // 位置.
            if ((right - left) >= 3)
            {
                ans.push_back({left, right - 1});
                // 注意, 让左指针跳过以检测到的相等的字符串.
                left = right - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution S;
    S.largeGroupPositions("abbxxxxzzy");

    return 0;
}