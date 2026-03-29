class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i = 0;
        while(i < 2)
        {
            char a = s1[i];
            char b = s1[i+2];
            if(a == s2[i] && b == s2[i+2])
            {
                i++;
                continue;
            }
            else if(b == s2[i] && a == s2[i+2])
            {
                i++;
            }
            else return false;
        }
        return true;
    }
};