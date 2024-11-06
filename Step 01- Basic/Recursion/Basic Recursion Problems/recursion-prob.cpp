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

// Q6 Sum of N numbers (Paramaterized)

void SumofN(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    SumofN(i - 1, sum + i);
}

// Q6 Sum of N numbers (functional)

int sumOfN(int n)
{
    if (n == 0)
        return 0;
    return n + sumOfN(n - 1);
}

// Q7 factorial

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

// Q8 Reverse an array

void reverseArray(int i, int arr[], int n){
   if(i>=2) return;
   swap(arr[i], arr[n-i-1]);
   reverseArray(i+1, arr,n);
}


// Q9 Check of String palindrome
bool stringPalindrome(int i, string &s){
        if(i>=s.size()/2) return true;
        if(s[i]!=s[s.size()-i-1]) return false;
        return stringPalindrome(i+1, s);
}

// Q10 Fibonacci Series (multiple recursion)

int fibonacciSeries(int n){
    if(n<=1) return n;
    int last = fibonacciSeries(n-1);
    int secondLast = fibonacciSeries(n-2);
    return last + secondLast;
}
int main()
{
    int n;
    cin >> n;
    // printName(1,n);
    // print1toN(1,n);
    // printNto1(n,n);
    // print1tonbybacktrak(n,n);
    // printNto1ByBackTrack(1, n);
    // SumofN(n,0);
    // cout<<sumOfN(n);
    // cout << fact(n);
    // int arr[n];
    // for(int i = 0; i<n; i++) cin>> arr[i];
    //     reverseArray(0,arr,n);
    // for(int i=0; i<n;i++) cout<<arr[i]<<" ";

    // string s = "madsam";
    // cout<<stringPalindrome(0,s);
    cout<<fibonacciSeries(n);
    return 0;
}