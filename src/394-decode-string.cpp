#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getDigits(string &s, size_t &ptr)
    {
        string ret = "";
        while (isdigit(s[ptr]))
        {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector<string> &v)
    {
        string ret;
        for (const auto &s : v)
        {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s)
    {
        vector<string> stack;

        size_t ptr = 0;

        while (ptr < s.size())
        {
            char cur = s[ptr];
            // 获取一个数字并入栈.
            if (isdigit(cur))
            {
                // 数字可能不止一位.
                string digits = getDigits(s, ptr);
                stack.push_back(digits);
            }
            // 获取一个字母或左括号并入栈.
            else if (isalpha(cur) || cur == '[')
            {
                // 生成一个字符串, 包含 1 个 s[ptr].
                stack.push_back(string(1, s[ptr++]));
            }
            // 如果为右括号.
            else
            {
                // 指针自增.
                ++ptr;

                // 存储出栈序列.
                vector<string> sub;
                while (stack.back() != "[")
                {
                    sub.push_back(stack.back());
                    stack.pop_back();
                }
                // 将出栈序列反转, 注意, sub 每个元素内部仍保持原来的顺序,
                // 例如 {"bcbc", "a"} 反转之后变为 {"a", "bcbc"}.
                reverse(sub.begin(), sub.end());

                // 左括号出栈.
                stack.pop_back();

                // 此时栈顶为当前 sub 对应的重复出现的次数. 将其转化为正整数.
                int repTime = stoi(stack.back());
                // 次数出栈.
                stack.pop_back();

                // 根据重复次数构造字符串.
                string t, o = getString(sub);
                while (repTime--)
                {
                    t += o;
                }

                // 将解析出来的结果入栈.
                stack.push_back(t);
            }
        }

        // 返回结果.
        return getString(stack);
    }
};

int main()
{
    string s = "2[a2[bc]]";
    Solution S;
    S.decodeString(s);

    return 0;
}
