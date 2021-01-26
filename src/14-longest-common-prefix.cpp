#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // 如果是空串.
        if (!strs.size())
        {
            return "";
        }

        // 取 strs[0] 为初始最长公共前缀.
        string prefix = strs[0];
        // 字符串数目.
        int count = strs.size();
        // 横向比较.
        for (int i = 1; i < count; ++i)
        {
            // 得到已知公共前缀和下一字符串之间的公共前缀.
            prefix = longestCommonPrefix(prefix, strs[i]);
            // 如果是空串, 结束算法.
            if (!prefix.size())
            {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string &str1, const string &str2)
    {
        // 取两字符串最小长度.
        int length = min(str1.size(), str2.size());
        int index = 0;
        // 逐个判断.
        while (index < length && str1[index] == str2[index])
        {
            ++index;
        }
        // 返回公共公共前缀.
        return str1.substr(0, index);
    }
};
