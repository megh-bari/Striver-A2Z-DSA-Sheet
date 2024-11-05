#include <bits/stdc++.h>

using namespace std;

// Q1
void printName(int i, int n)
{
    if (i > n)
        return;
    cout << "megh" << endl;
    printName(i + 1, n);
}

// Q2
void print1toN(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    print1toN(i + 1, n);
}

// Q3
void printNto1(int i, int n)
{
    if (i < 1)
        return;
    cout << i << endl;
    printNto1(i - 1, n);
}

// Q4 by Back Tracking

void print1tonbybacktrak(int i, int n)
{
    if (i < 1)
        return;
    print1tonbybacktrak(i - 1, n);
    cout << i << endl;
}

// Q5 by backTracking
void printNto1ByBackTrack(int i, int n)
{
    if (i > n)
        return;
    printNto1ByBackTrack(i + 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    // printName(1,n);
    // print1toN(1,n);
    // printNto1(n,n);
    // print1tonbybacktrak(n,n);
    printNto1ByBackTrack(1, n);
    return 0;
}