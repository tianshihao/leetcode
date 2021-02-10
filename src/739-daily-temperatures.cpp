#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> ans(n, 0);

        // 单调栈.
        stack<int> s;

        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && T[i] > T[s.top()])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution S;
    S.dailyTemperatures(nums);

    return 0;
}
