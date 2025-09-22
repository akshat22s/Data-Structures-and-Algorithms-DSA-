class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i : arr)
        {
            m[i]++;
        }
        int ans = 0;
        int ans2 = 0;
        for(auto const& [i, j] : m)
        {
            if(j > ans) ans = j;
        }
        for(auto const& [i, j] : m)
        {
            if(ans == j)
            {
                ans2 = ans2 + ans;
            }
        }
        return ans2;
    }
};