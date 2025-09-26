class Solution {
public:

    int binarySearch(vector<int>& nums, int low, int high, int sum)
    {
        int k = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(sum > nums[mid])
            {
                k = mid;
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return k;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n < 3) return 0;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) continue;
            for(int j = i+1; j < n; j++)
            {
                if(nums[j] == 0) continue;
                int sum = nums[i] + nums[j];
                int k = binarySearch(nums, j+1, n-1, sum);
                if(k != -1) count += (k - j);
            }
        }
        return count;
    }
};