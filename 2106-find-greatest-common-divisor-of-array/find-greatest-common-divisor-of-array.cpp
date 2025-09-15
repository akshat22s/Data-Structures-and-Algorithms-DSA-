class Solution {
public:
    int gcd(int m, int n)
    {
        if(n == 0) return m;
        return gcd(n, m%n);
    }
    int findGCD(vector<int>& nums) {
        int a = *max_element(nums.begin(),nums.end());
        int b = *min_element(nums.begin(),nums.end());
        return gcd(a,b);
    }
};