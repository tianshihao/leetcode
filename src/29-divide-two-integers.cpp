class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 特判.
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
            {
                return -dividend;
            }
            return INT_MAX;
        }

        long a = dividend;
        long b = divisor;

        // 符号.
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0))
        {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        // 计算结果.
        long res = div(a, b);
        // 防止溢出.
        if (sign > 0)
        {
            return res > INT_MAX ? INT_MAX : res;
        }
        return -res;
    }
    int div(long dividend, long divisor)
    {
        // 被除数小于除数.
        if (dividend < divisor)
        {
            return 0;
        }

        long count = 1;

        long doubleDivisor = divisor; // 除数不断翻倍.
        while ((doubleDivisor + doubleDivisor) <= dividend)
        {
            count = count + count;                         // 最小解翻倍.
            doubleDivisor = doubleDivisor + doubleDivisor; // 除数翻倍.
        }
        // 之后判断剩余的部分 dividend - doubleDivisor 的最小解. 直到被除数小于除数.
        return count + div(dividend - doubleDivisor, divisor);
    }
};
