class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v = 0; v < isConnected.size(); v++)
            {
                if(!visited[v] && isConnected[u][v] == 1)
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                BFS(isConnected, i, visited);
            }
        }
        return count;
    }
};