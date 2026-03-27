class Solution {
public:
    void BFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited, int &ver, int &edg)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ver++;
            edg += adj[curr].size();

            for(auto &v : adj[curr])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<bool> visited(n,false);
        for(int i = 0; i < n; i++)
        {
            
            if(!visited[i])
            {
                int ver = 0;
                int edg = 0;
                BFS(adj, i, visited, ver, edg);
                if((ver*(ver-1)) == edg) ans++;
            }
        }
        return ans;
    }
};