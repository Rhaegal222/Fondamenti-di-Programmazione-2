int fib (int n)
{
    int f, f1 = 0, f2 = 1;
    if ((n == 0) || (n == 1)) return n;
    else
    for (int i = 2; i < n; i++)
    {
        f = f1+f2;
        f2 = f1; f1 = f;
    }
    return f;
}