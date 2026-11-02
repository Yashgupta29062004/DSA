class Solution {
    int m, n;
    int memo[505][505];
    pair<int, int> jump_memo[505][505][2];
    int MOD = 1e9 + 7;

    // Helper to find where the robot lands if it enters (r, c) moving in 'dir'
    // dir: 0 for Right, 1 for Down
    pair<int, int> get_landing(int r, int c, int dir, const vector<vector<int>>& grid) {
        // Out of bounds
        if (r >= m || c >= n) return {-1, -1};
        
        // Landed on an empty cell
        if (grid[r][c] == 0) return {r, c};
        
        // Return cached landing destination if already computed
        if (jump_memo[r][c][dir].first != -2) return jump_memo[r][c][dir];

        pair<int, int> res;
        if (dir == 0) {
            // Entered moving Right, hit a mirror -> reflect Down
            res = get_landing(r + 1, c, 1, grid);
        } else {
            // Entered moving Down, hit a mirror -> reflect Right
            res = get_landing(r, c + 1, 0, grid);
        }
        
        return jump_memo[r][c][dir] = res;
    }

    // DP function to find paths from (r, c) to (m-1, n-1)
    int solve(int r, int c, const vector<vector<int>>& grid) {
        // Reached the destination
        if (r == m - 1 && c == n - 1) return 1;
        
        // Return cached path count if already computed
        if (memo[r][c] != -1) return memo[r][c];

        int paths = 0;
        
        // 1. Try moving Right
        pair<int, int> right_dest = get_landing(r, c + 1, 0, grid);
        if (right_dest.first != -1) { // If it didn't reflect out of bounds
            paths = (paths + solve(right_dest.first, right_dest.second, grid)) % MOD;
        }

        // 2. Try moving Down
        pair<int, int> down_dest = get_landing(r + 1, c, 1, grid);
        if (down_dest.first != -1) { // If it didn't reflect out of bounds
            paths = (paths + solve(down_dest.first, down_dest.second, grid)) % MOD;
        }

        return memo[r][c] = paths;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Initialize memo tables
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
                // -2 acts as our "unvisited" state for jump_memo
                jump_memo[i][j][0] = {-2, -2}; 
                jump_memo[i][j][1] = {-2, -2};
            }
        }
        
        return solve(0, 0, grid);
    }
};