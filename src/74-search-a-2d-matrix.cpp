#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rowNum = matrix.size();
        if (rowNum == 0)
        {
            return 0;
        }
        int colNum = matrix[0].size();

        int left = 0, right = rowNum * colNum - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midElem = matrix[mid / colNum][mid % colNum];
            if (midElem == target)
            {
                return true;
            }
            else
            {
                if (target < midElem)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};