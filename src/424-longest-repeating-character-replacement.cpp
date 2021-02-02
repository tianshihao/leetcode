#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        // 维护一个滑动窗口. 窗口中除了出现次数最多的字符外的字符不超过 k 个.
        int left = 0, right = 0;

        while (right < n)
        {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            // 如果窗口内除了最多字符外出现的非重复字符大于 k 个.
            if (right - left + 1 - maxn > k)
            {
                // 将窗口左沿剔除.
                num[s[left] - 'A']--;
                // 窗口左沿前移.
                left++;
            }
            // 窗口右沿前移.
            right++;
        }
        return right - left;
    }
};
