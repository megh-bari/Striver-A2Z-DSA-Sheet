#include<bits/stdc++.h>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &MATRIX) {


  int n = MATRIX.size();
  int m = MATRIX[0].size();
  int left = 0, right = m - 1;
  int top = 0, bottom = n - 1;
  vector<int> ans;

  while (top <= bottom && left <= right) {
    // right
    for (int i = left; i <= right; i++) {
      ans.push_back(MATRIX[top][i]);
    }
    top++;

    // bottom
    for (int i = top; i <= bottom; i++) {
      ans.push_back(MATRIX[i][right]);
    }
    // left
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        ans.push_back(MATRIX[bottom][i]);
      }
      bottom--;
    }

    // top
    if(left<=right){
      for (int i = bottom; i >= top; i--) {
        ans.push_back(MATRIX[i][left]);
      }
      left++;
    }
  }
  return ans;
}

int main(){
    return 0;
}