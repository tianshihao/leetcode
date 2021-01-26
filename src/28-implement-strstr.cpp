#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int needleLength = needle.length(), haystackLength = haystack.length();
        if (needleLength == 0)
        {
            return 0;
        }

        int pHaystack = 0;
        while (pHaystack < haystackLength - needleLength + 1)
        {
            // 在 haystack 找到和 needle 第一个字符匹配的位置.
            while (pHaystack < haystackLength - needleLength + 1 && haystack[pHaystack] != needle[0])
            {
                ++pHaystack;
            }

            // 计算最大匹配字符串.
            int currLen = 0, pNeedle = 0;
            while (pNeedle < needleLength && pHaystack < haystackLength && haystack[pHaystack] == needle[pNeedle])
            {
                ++pHaystack;
                ++pNeedle;
                ++currLen;
            }

            // 如果 needle 匹配完毕, 返回匹配开始位置.
            if (currLen == needleLength)
                return pHaystack - needleLength;

            // 否则, 回退.
            pHaystack = pHaystack - currLen + 1;
        }
        return -1;
    }
};

int main()
{
    Solution S;

    cout << S.strStr("hello", "ll") << endl;

    return 0;
}
