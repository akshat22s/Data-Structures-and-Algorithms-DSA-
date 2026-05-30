class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto &v : prerequisites)
        {
            int a = v[0];
            int b = v[1];

            // b -----> a
            adj[b].push_back(a);

            // arrow ja raha hai 'a' ma 
            indegree[a]++;
        }

        queue<int> q;
        
        for(int i = 0; i < n; i++)
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
            for(auto &v : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};