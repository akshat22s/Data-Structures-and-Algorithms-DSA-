class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    vector<vector<int>> direction{{1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0) return -1;

        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        vector<vector<int>> ans(n,vector<int>(n,INT_MAX));

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        pq.push({1,{0,0}});
        ans[0][0] = 1;

        while(!pq.empty())
        {
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();

            for(auto dir : direction)
            {
                int xd = x + dir[0];
                int yd = y + dir[1];

                int dist = 1;

                if(isSafe(xd,yd) && grid[xd][yd] == 0 && d + dist < ans[xd][yd])
                {
                    pq.push({d+dist, {xd,yd}});
                    grid[xd][yd] = 1;
                    ans[xd][yd] = d + dist;
                }
            }
        }
        if(ans[n-1][n-1] == INT_MAX) return -1;
        return ans[n-1][n-1];
    }
};