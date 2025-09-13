class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> m;
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        int vol = 0;
        int con = 0;
        for(auto x : m)
        {
            if(x.first == 'a' ||x.first == 'e' || x.first == 'i' || x.first == 'o' || x.first == 'u' )
            {
                vol = max(vol, x.second);
            }
            else
            {
                con = max(con, x.second);
            }
        }
        return vol + con;
    }
};