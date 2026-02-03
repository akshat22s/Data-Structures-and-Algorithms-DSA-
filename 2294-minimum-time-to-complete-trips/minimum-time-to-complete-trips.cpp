class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips)
    {
        long long trip = 0;
        for(int i = 0; i < time.size(); i++)
        {
            trip += mid/time[i];
        }
        if(trip < totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (*max_element(time.begin(),time.end())) * (long long) totalTrips;
        long long ans = -1;
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            if(check(mid, time, totalTrips))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};