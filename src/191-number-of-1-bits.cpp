﻿#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int bits = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i)
        {
            if ((n & mask) != 0)
            {
                ++bits;
            }
            mask <<= 1;
        }
        return bits;
    }
};

int main()
{
    Solution S;
    S.hammingWeight(00000000000000000000000000001011);

    return 0;
}
