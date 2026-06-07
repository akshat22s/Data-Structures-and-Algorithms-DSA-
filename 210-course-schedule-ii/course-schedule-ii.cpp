class Solution {
public:
    bool hasCycle;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRec, stack<int> &st)
    {
        visited[u] = true;
        inRec[u] = true;
        for(auto &v : adj[u])
        {
            if(inRec[v] == true) 
            {
                hasCycle = true;
                return;
            }
            if(visited[v] == false)
            {
                DFS(adj, v, visited, inRec, st);
            }
        }
        inRec[u] = false;
        st.push(u);

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : prerequisites)
        {
            int a = e[0];
            int b = e[1];

            adj[b].push_back(a);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> inRec(numCourses, false);
        hasCycle = false;
        stack<int> st;
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == false)
            {
                DFS(adj, i, visited, inRec, st);
            }
        }
        if(hasCycle == true) return {};
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};