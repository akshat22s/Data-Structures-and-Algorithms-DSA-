class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        // dp[n] = 1;
        // dp[n-1] = 1;

        for(int i = n; i >= 0; i--)
        {
            if(i == n || i == n-1) dp[i] = 1;
            else dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }
};