class Solution {
public:
    bool isThree(int n) {
        if(floor(sqrt(n)) != ceil(sqrt(n))) return false;
        int c = 0;
        for(int i = 1; i * i < n; i++)
        {
            if(n % i == 0) c++;
            if(c > 1) return false;
        }
        return c == 1;
    }
};