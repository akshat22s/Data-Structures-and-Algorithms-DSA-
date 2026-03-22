class Solution {
public:
    typedef pair<int,int> pi;
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<pi> pq;
        int n = score.size();
        for(int i = 0; i < n; i++)
        {
            pq.push({score[i],i});
        }
        vector<string> ans(n,"");
        int x = 0;
        while(!pq.empty())
        {
            x++;
            if(x == 1) ans[pq.top().second] = "Gold Medal";
            else if(x == 2) ans[pq.top().second] = "Silver Medal";
            else if(x == 3) ans[pq.top().second] = "Bronze Medal";
            else ans[pq.top().second] = to_string(x);
            pq.pop();
        }
        return ans;
    }
};