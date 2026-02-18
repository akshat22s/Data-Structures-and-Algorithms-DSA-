class Solution {
public:
    int dp[45];
    int helper(int n, int idx)
    {
        if(n == idx || n-1 == idx) return 1;
        if(dp[idx] != -1) return dp[idx];
        int oneS = helper(n, idx+1);
        int twoS = helper(n, idx+2);

        return dp[idx] = oneS + twoS;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0);
    }
};