#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int n = A.size();

        int left = 0, right = 0;
        int lsum = 0, rsum = 0;

        int ans = 0;

        for (right = 0; right < n; ++right)
        {
            rsum += 1 - A[right];
            while (lsum < rsum - K)
            {
                lsum += 1 - A[left];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
