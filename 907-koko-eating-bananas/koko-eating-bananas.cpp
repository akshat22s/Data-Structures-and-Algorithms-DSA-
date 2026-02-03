class Solution {
public:
    bool check(int mid, vector<int>& piles, int h)
    {
        long long count = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++)
        {
            if(mid >= piles[i]) count++;
            else if(piles[i] % mid == 0) count += piles[i]/mid;
            else count += (piles[i]/mid + 1);
        }
        if(count <= h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,piles,h))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;

    }
};