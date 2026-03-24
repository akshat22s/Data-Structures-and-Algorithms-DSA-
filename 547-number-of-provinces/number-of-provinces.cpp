class Solution {
public:
    void BFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto &v : adj[curr])
            {
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
            // q.pop();
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int,vector<int>> adj;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                BFS(adj, i, visited);
            }
        }
        return count;
    }
};