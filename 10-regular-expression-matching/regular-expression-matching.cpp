class Solution {
public:
    bool solve(string s, string p)
    {
        if(p.size() == 0)
        {
            if(s.size() == 0) return true;
            return false;
        }
        bool firstMatch = false;
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
        {
            firstMatch = true;
        }
        if(p[1] == '*')
        {
            bool skip = solve(s, p.substr(2));
            bool take = (firstMatch && solve(s.substr(1),p));
            return take || skip;
        }
        else return (firstMatch && solve(s.substr(1), p.substr(1)));

        
    }
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};