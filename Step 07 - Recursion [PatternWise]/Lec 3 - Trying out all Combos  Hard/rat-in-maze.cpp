void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU"; //  Down, Left, Right, Up
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
        {
            vis[nexti][nextj] = 1; // Mark the new cell as visited
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[nexti][nextj] = 0; // Unmark after the recursive call
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    int n = mat.size(); // size of the matrix
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1}; // Direction arrays for Down, Left, Right, Up
    int dj[] = {0, -1, 1, 0};

    if (mat[0][0] == 1)
    {
        vis[0][0] = 1; // Mark the starting point as visited
        solve(0, 0, mat, n, ans, "", vis, di, dj);
    }

    return ans;
}
