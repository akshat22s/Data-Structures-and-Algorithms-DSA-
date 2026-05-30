class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int u)
    {
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == false && isConnected[u][v] == 1)
            {
                DFS(isConnected, visited, v);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
            {
                count++;
                DFS(isConnected, visited, i);
            }
        }
        return count;
    }
};