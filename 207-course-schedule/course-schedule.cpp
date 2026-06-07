class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRec)
    {
        visited[u] = true;
        inRec[u] = true;
        for(auto &v : adj[u])
        {
            if(visited[v] == false)
            {
                if(DFS(adj, v, visited, inRec)) return true;
            }
            else
            {
                if(inRec[v] == true) return true;
            }
        }
        inRec[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : prerequisites)
        {
            int a = e[0];
            int b = e[1];

            // b -------> a 
            // phela b karo uska baad a karo
            adj[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRec(numCourses, false);

        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == false)
            {
                if(DFS(adj, i, visited, inRec)) return false;
            }
        }
        return true;
    }
};