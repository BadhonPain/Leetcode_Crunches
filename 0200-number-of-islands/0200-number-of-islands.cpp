class Solution {
public:
    void dfs(int i, int j, const vector<vector<char>>& grid,
             vector<vector<bool>>& is_visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || is_visited[i][j] ||
            grid[i][j] != '1')
            return;
        is_visited[i][j] = true;
        dfs(i - 1, j, grid, is_visited);
        dfs(i + 1, j, grid, is_visited);
        dfs(i, j - 1, grid, is_visited);
        dfs(i, j + 1, grid, is_visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int numOfIsland = 0;
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !is_visited[i][j]) {
                    dfs(i, j, grid, is_visited);
                    numOfIsland++;
                }
            }
        }
        return numOfIsland;
    }
};