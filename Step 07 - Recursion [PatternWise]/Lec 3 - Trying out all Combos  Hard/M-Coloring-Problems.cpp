bool isSafe(int node, int color[], vector<pair<int, int>>& edges, int N, int col) {
        for (auto& edge : edges) {
            int u = edge.first, v = edge.second;
            if (u == node && color[v] == col)
                return false;
            if (v == node && color[u] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, int color[], int m, int N, vector<pair<int, int>>& edges) {
        if (node == N)
            return true;
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, edges, N, i)) {
                color[node] = i;
                if (solve(node + 1, color, m, N, edges))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        int color[v];
        memset(color, 0, sizeof(color)); 
        if (solve(0, color, m, v, edges))
            return true;
        return false;
    }