class Solution {
public:
    typedef pair<int,int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pi>> adj;
        for(auto &e : times)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> ans(n+1, INT_MAX);

        ans[k] = 0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it : adj[node])
            {
                int adjNode = it.first ;
                int dist = it.second;

                if(d + dist < ans[adjNode])
                {
                    ans[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
        int x = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            x = max(x, ans[i]);
        }
        return x == INT_MAX ? -1 : x;
    }
};