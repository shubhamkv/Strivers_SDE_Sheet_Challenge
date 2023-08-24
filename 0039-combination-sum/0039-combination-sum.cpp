class Solution {
public:
     vector<vector<int>> ans;
    
    void comb(int i, int target, vector<int> &nums, vector<int> &temp)
    {
        if(i==nums.size())
        {
            if(target==0)
               ans.push_back(temp);
            return;
        }
        if(nums[i]<=target)
        {
            temp.push_back(nums[i]);
            comb(i,target-nums[i],nums,temp);
            temp.pop_back();
        }
        comb(i+1,target,nums,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> temp;
        comb(0,target,nums,temp);
        return ans;
    }
};