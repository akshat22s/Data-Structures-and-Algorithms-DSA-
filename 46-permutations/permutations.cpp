class Solution {
public:
    void generate(vector<int>& nums, vector<int> ans, vector<vector<int>> &finalAns)
    {
        if(nums.size() == 0)
        {
            finalAns.push_back(ans);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            ans.push_back(x);
            nums.erase(nums.begin()+i);
            generate(nums, ans, finalAns);
            ans.pop_back();
            nums.insert(nums.begin()+i, x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        generate(nums, ans, finalAns);
        return finalAns;
    }
};