#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> Stack;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                Stack.push(s[i]);
            }
            else
            {
                // ())))))
                if (Stack.size() == 0)
                {
                    return false;
                }

                char leftBracket = Stack.top();
                Stack.pop();

                if (s[i] == ')' && leftBracket == '(')
                {
                    continue;
                }
                if (s[i] == '}' && leftBracket == '{')
                {
                    continue;
                }
                if (s[i] == ']' && leftBracket == '[')
                {
                    continue;
                }

                // (}, (], {), {], [), [}
                return false;
            }
        }

        // ((((((()
        if (Stack.size() != 0)
        {
            return false;
        }

        // valid.
        return true;
    }
};

int main()
{
    Solution S;

    if (S.isValid("(]"))
    {
        cout << "valid\n";
    }
    else
    {
        cout << "invalid\n";
    }

    return 0;
}