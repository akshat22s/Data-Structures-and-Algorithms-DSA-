class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool ans = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') ans = true;
            if(i != 0 && ans == true)
            {
                if(s[i] == '1' && s[i-1] != '1') return false;
            }
        }
        return ans;
    }
};