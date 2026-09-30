class Solution {
    int m, n;
    
public:
    bool fun(int i, int j, int openCount, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        // Base edge checks & invalid sequence checks
        if (i >= m || j >= n || openCount < 0) return false;

        // Update bracket count for current cell
        if (grid[i][j] == '(') {
            openCount++;
        } else {
            openCount--;
        }
        int remainingSteps = (m - 1 - i) + (n - 1 - j);
        if (openCount < 0 || openCount > remainingSteps) return false;

        // If openCount drops below 0 at any point, it's invalid
        if (openCount < 0) return false;

        // Reached destination cell (m-1, n-1)
        if (i == m - 1 && j == n - 1) {
            return openCount == 0;
        }

        // Return cached result if already computed
        if (dp[i][j][openCount] != -1) {
            return dp[i][j][openCount];
        }

        // Try moving down or right
        bool down = fun(i + 1, j, openCount, grid, dp);
        bool right = fun(i, j + 1, openCount, grid, dp);

        return dp[i][j][openCount] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length is m + n - 1; if odd, valid matching is impossible
        if ((m + n - 1) % 2 != 0) return false;

        // Max possible open brackets is bounded by (m + n) / 2
        int maxOpen = (m + n) / 2;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxOpen + 1, -1)));

        return fun(0, 0, 0, grid, dp);
    }
};