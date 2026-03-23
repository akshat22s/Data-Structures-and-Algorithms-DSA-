class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& isConnected, int u, vector<bool> &visited)
    {
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && isConnected[u][v] == 1)
            {
                DFS(isConnected, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        // // make graph by matrix representation
        // unordered_map<int, vector<int>> adj;
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
            if(!visited[i])
            {
                count++;
                DFS(isConnected, i, visited);
            }
        }
        return count;
    }
};