class Solution {
public:
    int m, n;
    vector<pair<int, int>> directions = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    void bfs(vector<vector<int>> &grid, queue<pair<int, int>> q) {
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc]: directions) {
                int r = row + dr;
                int c = col + dc;
                if (r >= 0 && r < m
                    && c >= 0 && c < n
                    && grid[r][c] == INT_MAX) {
                        grid[r][c] = min(grid[r][c], grid[row][col] + 1);
                        q.push({r, c});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        bfs(grid, q);
    }
};
