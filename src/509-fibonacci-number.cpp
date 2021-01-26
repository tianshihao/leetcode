class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            return this->fib(n - 1) + this->fib(n - 2);
        }
    }
};
