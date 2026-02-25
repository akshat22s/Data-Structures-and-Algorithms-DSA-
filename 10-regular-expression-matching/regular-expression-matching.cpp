class Solution {
public:
    int dp[25][25];
    bool solve(int i, int j, string s, string p)
    {
        if(j == p.size())
        {
            if(i == s.size()) return true;
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool firstMatch = false;
        if(i < s.size() && (p[j] == s[i] || p[j] == '.'))
        {
            firstMatch = true;
        }
        if(p[j+1] == '*')
        {
            bool skip = solve(i, j+2, s, p);
            bool take = (firstMatch && solve(i+1, j, s, p));
            return dp[i][j] = take || skip;
        }
        else return dp[i][j] = (firstMatch && solve(i+1, j+1, s, p));

        
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};