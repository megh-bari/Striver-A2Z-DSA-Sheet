#include <bits/stdc++.h>

using namespace std;

int unionArray(int arr1[], int arr2[], int n1, int n2, int uni[]){
    set<int>st;
    for(int i=0; i<n1; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(arr2[i]);
    }
    int i = 0;
    for (auto it : st) {
        uni[i++] = it; 
    }
    return i;
    
}
int main()
{
     int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    int uni[n1+n2];
    int uniSize = unionArray(arr1, arr2, n1, n2, uni);
    for(int i=0; i<uniSize; i++){
        cout<<uni[i]<<" ";
    }
    return 0;

}