class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> m;
        int a, b;
        int n = grid.size();
        for(auto x : grid)
        {
            for(int y : x)
            {
                m[y]++;
            }
        }

        for(int t = 1; t <= n*n; t++)
        {
            if(m[t] == 2) a = t;
            if(m[t] == 0) b = t;
        }
        return {a,b};
    }
};