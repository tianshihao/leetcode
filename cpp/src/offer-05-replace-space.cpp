#include <string>
using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string ans;

        for (auto &c : s)
        {
            if (c == ' ')
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
