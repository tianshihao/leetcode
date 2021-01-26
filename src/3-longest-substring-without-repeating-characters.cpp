#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 字符哈希集合.
        unordered_set<char> occ;
        // 字符串长度.
        int n = s.size();
        // 滑动窗口右指针.
        int rk = -1;
        // 答案.
        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                // 除了第一次, 每次 for 循环滑动窗口左指针向右移动一格.
                occ.erase(s[i - 1]);
            }

            // 在右指针右移后不越界并且右移后指向的字符是未出现过的字符时
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                // 将新未出现过的, 不重复的字符加入到哈希集合中.
                occ.insert(s[rk + 1]);
                // 在更新滑动窗口右指针.
                ++rk;
            }

            // 每趟循环更新不含有重复字符的最长子串的最大长度.
            ans = max(ans, rk - i + 1);
        }

        return ans;
    }
};

int main()
{
    Solution S;

    cout << S.lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}
