#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        // len 是每次判断长度为 len 的子串是否为回文串.
        for (int len = 0; len < n; ++len)
        {
            // 从 i 开始, 类似滑动窗口, 只是窗口大小固定, 为 len.
            for (int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                // 边界条件: 长度为 1 的子串.
                if (len == 0)
                {
                    dp[i][j] = 1;
                }
                // 边界条件: 长度为 2 的子串.
                else if (len == 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                // 一般情况, 按照状态转移方程.
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                // 如果 s[i:j] 是回文子串且该回文串的长度 len + 1 大于之前的回文串.
                if (dp[i][j] && len + 1 > ans.size())
                {
                    // 则更新答案.
                    ans = s.substr(i, len + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;

    cout << S.longestPalindrome("babad") << endl;

    return 0;
}
