1) Swap two num :
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

2) Check If i’th bit is set or not :
    (n &(1<<k))

3) Set The i’th bit :
    (n | (1<<i))

4) Clear the ith bit :
    (n & ~(1<<i))

5) Toggle the ith bit :
    (n ^ (1<<i))

6) Remove last set bit (rightmost) :
    for set : (n | n + 1)
    for unset : (n & n - 1)

7) Check if the number is a power of 2 :
    ((n & n - 1)==0)

8) Check Number is odd or even :
    if(n&1) return false;
    return true;

9) Count number of set bits (C++ user) :  
    int ans= __builtin_popcount(Num);