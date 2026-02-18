class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1;
        int b = 1;
        int c;
        for(int i = n-2; i >= 0; i--)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};