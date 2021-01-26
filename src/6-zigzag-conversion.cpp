#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 如果只有 1 行.
        if (numRows == 1)
        {
            return s;
        }

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
            {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        // 将答案拼接起来.
        string ret;
        for (string row : rows)
        {
            ret += row;
        }
        return ret;
    }
};

int main()
{
    Solution S;

    cout << S.convert("LEETCODEISHIRING", 4) << endl;

    return 0;
}