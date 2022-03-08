int fibr(int n)
{
    if ((n == 0) || (n == 1)) return n;
    return fibr(n-1) + fibr(n-2);
}