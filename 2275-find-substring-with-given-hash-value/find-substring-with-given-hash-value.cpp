class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long h = 0, bp = 1;
        string ans = "";
        int n = s.size();
        for(int i = 1; i < k; i++) bp = (bp * power) % modulo;
        for(int i = n-1; i >= n-k; i--) h = ((h * power) % modulo + s[i] - 'a' + 1) % modulo;
        if(h == hashValue) ans = s.substr(n-k,k);
        for(int i = n-1; i >= k; i--)
        {
            h = (s[i-k] - 'a' + 1 + (h - ((s[i] - 'a' + 1) * bp) % modulo + modulo) * power % modulo) % modulo;
            if(h == hashValue) ans = s.substr(i - k, k);
        }
        return ans;
    }
};