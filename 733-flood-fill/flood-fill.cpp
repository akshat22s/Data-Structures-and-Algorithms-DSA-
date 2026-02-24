class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int currRow, int currCol, int initialColor, int color)
    {
        int m = image.size(); // row
        int n = image[0].size(); // col
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
        {
            return;
        }
        if(image[currRow][currCol] != initialColor)
        {
            return;
        }
        image[currRow][currCol] = color;
        dfs(image, currRow-1, currCol, initialColor, color); // up
        dfs(image, currRow, currCol+1, initialColor, color); // right
        dfs(image, currRow+1, currCol, initialColor, color); // dowm
        dfs(image, currRow, currCol-1, initialColor, color); // left
    }
};