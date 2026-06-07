class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }
        vector<int> indegree(numCourses, 0);
        for(int u = 0; u < numCourses; u++)
        {
            for(auto &v : adj[u])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
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
        if(ans.size() == numCourses) return ans;
        else return {};
        
    }
};