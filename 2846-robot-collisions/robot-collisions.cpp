class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n = positions.size();
        vector<pair<int,int>> act;
        for(int i = 0; i < n; i++)
        {
            act.push_back({positions[i],i});
        }
        sort(act.begin(), act.end());
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            int pos = act[i].first;
            int idx = act[i].second;
            if(directions[idx] == 'R')
            {
                st.push(idx);
            }
            if(directions[idx] == 'L')
            {
                while(!st.empty() && healths[idx] != 0)
                {
                    int curr = st.top();
                    st.pop();

                    if(healths[curr] == healths[idx])
                    {
                        healths[curr] = 0;
                        healths[idx] = 0;
                    }
                    else if(healths[curr] > healths[idx])
                    {
                        healths[curr]--;
                        healths[idx] = 0;
                        st.push(curr);
                    }
                    else
                    {
                        healths[curr] = 0;
                        healths[idx]--;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(healths[i] != 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};