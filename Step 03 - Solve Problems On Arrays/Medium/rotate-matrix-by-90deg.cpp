#include <bits/stdc++.h>

using namespace std;


// brute force

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = ans[i][j];
        }
    }
}


// better

#include<bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat) {
  int n = mat.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    reverse(mat[i].begin(), mat[i].end());
  }
}