class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> t = arr;
        for(int row = n-2; row >= 0; row--)
        {
            for(int col = 0; col <= row; col++)
            {
                t[row][col] = t[row][col] + min(t[row+1][col], t[row+1][col+1]);
            }
        }
        return t[0][0];
    }
};