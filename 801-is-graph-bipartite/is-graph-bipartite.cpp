class Solution {
public:
    bool isBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int> &color, int currColor)
    {
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto &v : adj[u])
            {
                if(color[v] == color[u]) return false;
                else if(color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int> color(V,-1);
        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
                if(isBipartiteBFS(adj, i, color, 0) == false) return false;
            }
        }
        return true;
    }
};