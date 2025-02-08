// set

int setBit(int n)
{

    return (n | (n + 1));
}

// unset

int setBit(int n)
{

    return (n & (n - 1));
}