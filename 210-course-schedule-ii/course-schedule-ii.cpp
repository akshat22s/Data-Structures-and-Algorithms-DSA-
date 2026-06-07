class Solution {
public:
    vector<int> topo(int V, unordered_map<int, vector<int>> &adj, vector<int> &ans)
    {
        queue<int> q;
        vector<int> indegree(V, 0);

        for(int u = 0; u < V; u++)
        {
            for(auto &v : adj[u])
            {
                indegree[v]++;
            }
        }

        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto &v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int, vector<int>> adj;
       for(auto &vec : prerequisites)
       {
            int a = vec[0];
            int b = vec[1];

            // b ----> a
            // phela b karo uska baad a ko karo
            adj[b].push_back(a);
        }
        vector<int> ans;
        topo(numCourses, adj, ans);
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};