class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i : nums)
        {
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(pq.size() > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};