double myPow(double x, int n)
{
    double ans = 1.0;
    long long copy = n;

    if (copy < 0)
        copy = -1 * copy; // negative to positive

    while (copy)
    {
        // odd
        if (copy % 2)
        {
            ans = ans * x;
            copy = copy - 1;
        }
        // even
        else
        {
            x = x * x;
            copy = copy / 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}