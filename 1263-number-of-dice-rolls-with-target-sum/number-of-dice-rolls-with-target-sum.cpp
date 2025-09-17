class Solution {
public:
    // Helper function to compute number of ways to roll 'diceCount' dice
    // with 'faces' faces each to get sum equal to 'targetSum'.
    int countWays(int diceCount, int faces, int targetSum, vector<vector<int>>& dp) {
        // Base Case: If no dice left and target sum is 0, this is a valid way
        if (diceCount == 0 && targetSum == 0) return 1;

        // If no dice left but targetSum is not 0, it's invalid
        if (diceCount == 0) return 0;

        // If already computed, return memoized value
        if (dp[diceCount][targetSum] != -1) return dp[diceCount][targetSum];

        long long totalWays = 0;
        const int MOD = 1e9 + 7;

        // Try all face values from 1 to 'faces'
        for (int face = 1; face <= faces; ++face) {
            if (targetSum - face < 0) continue;

            // Recursive call for one less dice and reduced target
            totalWays = (totalWays + countWays(diceCount - 1, faces, targetSum - face, dp)) % MOD;
        }

        // Store and return the computed result
        return dp[diceCount][targetSum] = totalWays;
    }

    int numRollsToTarget(int n, int k, int target) {
        // Initialize DP array with -1
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return countWays(n, k, target, dp);
    }
};