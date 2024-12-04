#include<bits/stdc++.h>

using namespace std;


int buyAndSell(int prices[], int n){
    int mini = prices[0], profit=0;
    for(int i=1; i<n; i++){
        int cost = prices[i]-mini;
        profit = max(profit,cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    int prices[n];

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    cout<<buyAndSell(prices,n);


    return 0;
}