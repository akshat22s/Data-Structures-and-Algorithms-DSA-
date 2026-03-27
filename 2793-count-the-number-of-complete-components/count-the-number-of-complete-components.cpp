class Solution {
public:
    void DFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited, int &ver, int &edg)
    {
        visited[u] = true;
        ver++;
        edg += adj[u].size();
        for(auto &v : adj[u])
        {
            if(!visited[v])
            {
                DFS(adj, v, visited, ver, edg);
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
                DFS(adj, i, visited, ver, edg);
                if((ver*(ver-1)) == edg) ans++;
            }
        }
        return ans;
    }
};