class Solution {
public:
    int dp[1001][1001];
    int helper(string& text1, string& text2, int i, int j)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + helper(text1, text2, i-1, j-1);
        }
        int la = helper(text1,text2, i-1, j);
        int ra = helper(text1, text2, i, j-1);

        return dp[i][j] = max(la,ra);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size()-1;
        int n = text2.size()-1;
        memset(dp,-1,sizeof(dp));
        return helper(text1, text2, m, n);
    }
};