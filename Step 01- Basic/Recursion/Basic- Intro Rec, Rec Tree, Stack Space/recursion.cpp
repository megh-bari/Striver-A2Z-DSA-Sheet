#include<bits/stdc++.h>

using namespace std;

// avoid to write infinite recursion
// void print(){
//     cout<<1<<endl;
//     print(); // stack overflow
// }

// recursion

void recursion(int count = 0){
    if (count==4) return;
    cout<<count<<endl;
    count++;
    recursion(count);
    
}


int main(){
    // print();
    recursion();
    return 0;
}