#include <bits/stdc++.h>

using namespace std;

void numberOfDigit(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lastDigit;
        lastDigit = n % 10; // its for extraction of digit
        n = n / 10;
        count += 1;
    }
    cout << count << endl;
}

// 0r

int numOfDig(int n)
{
    int count = (int)(log10(n) + 1);
    return count;
}

int reverseNumber(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int lastDigit = n % 10;
        n = n / 10;
        rev = (rev * 10) + lastDigit;
    }
    cout << rev;
}

int checkPalindrom(int n)
{
    int rev = 0;
    int x = n;
    while (n > 0)
    {
        int ld = n % 10;
        rev = (rev * 10) + ld;
        n = n / 10;
    }
    if (rev == x)
        cout << "palindrom";
    else
        cout << "not palindrom";
}

int amstrongNumber(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int ld = n % 10;
        sum = sum + (ld * ld * ld);
        n = n / 10;
    }
    cout << sum;
}

int printAllDivisor(int n)
{
    vector<int> ls;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if ((n / i) != i)
            {
                ls.push_back(n / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls)
        cout << it << " ";
}

int primeNumber(int n)
{
    int count = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
                count++;
        }
    }
    if (count == 2)
        cout << "Prime Number";
    else
        cout << "Not a Prime Number";
}

int gcdAndHcf(int n1, int n2)
{
    int gcd = 1;
    for (int i = min(n1, n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
            break;
        }
    }
    return gcd;
}

int euclideanAlgo(int a,int b){
    while (a>0 & b>0)
    {
        if(a>b) a= a%b;
        else b=b%a;
    }
    if(a==0) return b;
    else return a; 
}


int main()
{

    int n;
    cin >> n;
    // numberOfDigit(n);
    // reverseNumber(n);
    // checkPalindrom(n);
    // amstFrongNumber(n);
    // printAllDivisor(n);
    // primeNumber(n);

    // int n1=48;
    // int n2=18;
    // int result = gcdAndHcf(n1, n2);
    // cout << "GCD of " << n1 << " and " << n2 << " is: " << result << endl;

    int a=20, b=15;
    int result = euclideanAlgo(a,b);
    cout<<result<<endl;

    return 0;
}