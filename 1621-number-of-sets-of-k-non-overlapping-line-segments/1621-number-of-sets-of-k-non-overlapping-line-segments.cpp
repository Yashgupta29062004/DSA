class Solution {
public:
    int M = 1e9 + 7;
    int numberOfSets(int n, int k) {
        
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        
        // Base case: 0 segments can be formed in 1 way for any number of points
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        
        // OPTIMIZATION: Swap the loops! Iterate segments (o) first, then points (i)
        for(int o = 1; o <= k; o++){
            
            long long runningSum = 0; // This replaces the j-loop entirely!
            
            for(int i = 1; i < n; i++){
                int skip = dp[i-1][o];
                
                // Add the previous point's combinations from the previous segment count
                runningSum = (runningSum + dp[i-1][o-1]) % M;
                
                long long take = runningSum;
                
                dp[i][o] = (skip + take) % M;
            }
        }

        return dp[n-1][k];
    }
};