#include <bits/stdc++.h>

using namespace std;

// void printName(string name){
//     cout<<"Hey "<<name<<endl;
// }

// int sum(int a, int b){
//     return a + b;
// }

// int maximum(int x, int y){
//     if (x>=y)
//     {
//         return x;
//     }else{
//         return y;
//     }

// }

// void passbyValue(int num)
// {
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
// }

// void passByRefer(string &s)
// {
//     s[0] = 'b';
//     cout << s << endl;
// }

void doSomething(int arr[], int n)
{
    arr[0] += 100;
    cout<<"the value inside function"<<arr[0]<<endl;
}

int main()
{

    //! Data Typesb

    // int x, y;
    // cin >> x >> y;
    // cout << "value of x: " << x <<  " and y: " << y;

    // float y = 10.5;
    // double y = 100.2;
    // cout << "The value of v: " << y;

    // string str;
    // getline(cin, str);
    // cout<<str;

    // char ch;
    // cin >> ch;
    // cout << ch;

    //! if-else statements

    // Q) WAP that takes an input of age and print if you are adult or not
    // int age;
    // cin >> age;
    // if (age >= 18)
    // {
    //     cout << "You are an adult";
    // }
    // else
    // {
    //     cout << "You are not an adult";
    // }

    /*
    A School has following rules for grading system
    a. below 25 -F
    b. 25 to 44 - E
    c. 45 to 49 - D
    d. 50 to 59 - C
    e. 60 to 79 - B
    f. 80 to 100 - A

    aks user to enter marks and print marks and according grade
    */

    // int marks;
    // cin >> marks;

    // if (marks < 25)
    // {
    //     cout << "F";
    // }
    // else if (marks<=44)
    // {
    //     cout<<"E";
    // }
    //  else if (marks<=49)
    // {
    //     cout<<"D";
    // }
    //  else if (marks<=59)
    // {
    //     cout<<"C";
    // }
    //  else if (marks<=79)
    // {
    //     cout<<"B";
    // }
    //  else if (marks<=100)
    // {
    //     cout<<"A";
    // }

    // else
    // {
    //     cout << "Invalid Number. Please enter marks between 0 to 100";
    // }

    /*
    take the age from the user and them decicde accordingly
    1. If age<18 - not eligible for job
    2. If age>=55 and age<=57 - eligible for job, but retirement soon
    3. If age>57 - retirement time
    */

    // int age;
    // cin >> age;

    // if (age < 18)
    // {
    //     cout << " you are not eligible for job";
    // }
    // else if (age <= 57)
    // {
    //     cout << " you are eligible for job";
    //     if (age >= 55)
    //     {
    //         cout << " , but retirement soon";
    //     }
    // }
    // else
    // {
    //     cout << "retirement time";
    // }

    //! switch statement

    /*
    Take the day and print the corresponding day
    for 1 print monday and continue...
     */

    // int day;
    // cin>>day;
    // switch (day)
    // {
    // case 1:
    //     cout << "Monday";
    //     break;
    // case 2:
    //     cout << "Tuesday";
    //     break;
    // case 3:
    //     cout << "Wednesday";
    //     break;
    // case 4:
    //     cout << "Thursday";
    //     break;
    // case 5:
    //     cout << "Friday";
    //     break;
    // case 6:
    //     cout << "Saturday";
    //     break;
    // case 7:
    //     cout << "Sunday";
    //     break;

    // default:
    //     cout<<"Invalid Number!";
    //     break;
    // }

    //! Array

    //? 1D Array

    // int arr[5];
    // cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
    // arr[4]+=5;
    // cout<<arr[4];

    //? 2D Array

    // int arr[3][3];
    // arr[1][3] = 78;
    // cout<<arr[1][3];

    //? Strings

    // string s = "Megh";
    // int len = s.size();
    // s[len-1]= 'a';
    // cout<<s[len-1];

    //? for loop

    // for (int i = 1; i <=10; i++)
    // {
    //     cout<<"MEGH"<<endl;
    // }

    //? while loop

    // int i=1;
    // while (i<=5)
    // {
    //     cout<<"Hi"<<endl;
    //     i++;
    // }

    //? do-while

    // int i = 2 ;
    // do
    // {
    //    cout<<i;
    //    i++;
    // } while (i<=1);

    //? Function

    // string name;
    // cin>>name;
    // printName(name);

    // string name2;
    // cin>>name2;
    // printName(name2);

    // int a,b;
    // cin>>a>>b;
    // int result = sum(a,b);
    // cout<<"The sum of two number is : "<<result;

    // int x,y;
    // cin>>x>>y;
    // int max = maximum(x,y);
    // cout<<max;

    //* Pass by value

    // int num = 10;
    // passbyValue(num);
    // cout<<num<<endl;

    //* Pass by reference
    // string s = "hi";
    // passByRefer(s);
    // cout << s << endl;

    //! Looping the array

    int n = 5;
    int arr[n];

    for (int i = 0; i <=n; i++)
    {
        cin >> arr[i];
    }
    doSomething(arr, n);
    cout<<"the value inside int main: "<<arr[0]<<endl;

    return 0;
}
