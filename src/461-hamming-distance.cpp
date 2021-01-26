#include <bitset>
using namespace std;
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        return bitset<32>(x ^ y).count();
    }
};

int main()
{
    Solution S;
    S.hammingDistance(1, 4);

    return 0;
}