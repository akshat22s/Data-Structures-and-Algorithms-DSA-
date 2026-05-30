class Solution {
public:
    int n;
    void BFS(vector<vector<int>>& isConnected, int u, vector<bool> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v = 0; v < n; v++)
            {
                if(visited[v] == false && isConnected[u][v] == 1)
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        // unordered_map<int,vector<int>> adj;
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(isConnected[i][j] == 1)
        //         {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
            {
                BFS(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};