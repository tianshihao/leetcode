#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> monoStack;
        for (int i = 0; i < n; ++i)
        {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i])
            {
                monoStack.pop();
            }
            left[i] = (monoStack.empty() ? -1 : monoStack.top());
            monoStack.push(i);
        }

        monoStack = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i])
            {
                monoStack.pop();
            }
            right[i] = (monoStack.empty() ? n : monoStack.top());
            monoStack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};