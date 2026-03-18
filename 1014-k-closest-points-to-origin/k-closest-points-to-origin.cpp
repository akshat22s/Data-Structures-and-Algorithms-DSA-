class Solution {
public:
    typedef pair<int, vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        int n = points.size();
        for(auto &it : points)
        {
            int ans = it[0] * it[0] + it[1] * it[1];
            pq.push({ans,it});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while(pq.size() != 0)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};