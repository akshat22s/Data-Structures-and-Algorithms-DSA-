class Solution {
public:
    bool topoSortCheck(unordered_map<int,vector<int>> &adj, int n, vector<int> &indegree)
    {
        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto &v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == n) return true;
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses, false);  // kahn's algo

        for(auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];

            // v ----> u
            adj[v].push_back(u);

            // arrow ja raha hai 'u' me
            indegree[u]++;
        }

        return topoSortCheck(adj, numCourses, indegree);
    }
};