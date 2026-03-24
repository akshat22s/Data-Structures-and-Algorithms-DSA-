class Solution {
public:
    vector<int> topologicalSortCheck(unordered_map<int,vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans)
    {
        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
                ans.push_back(i);
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
                    ans.push_back(v);
                }
            }
        }
        if(count == n) return ans;
        else return {};
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n, 0);  // Kahn's Algo

        for(auto &e : prerequisites)
        {
            int u = e[0];
            int v = e[1];
            // v ----> u
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int> ans;
        return topologicalSortCheck(adj, n, indegree, ans);
    }
};