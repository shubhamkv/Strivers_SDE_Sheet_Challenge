class Solution {
public:

    // Brute force Approach : It Gives TLE 

    // set<vector<int>> ans;
    
    // void comb(int i, int target, vector<int> &nums, vector<int> &temp)
    // {
    //     if(i==nums.size())
    //     {
    //         if(target==0)
    //            ans.insert(temp);
    //         return;
    //     }
    //     // picking an element on particular index
    //     if(nums[i]<=target)
    //     {
    //         temp.push_back(nums[i]);
    //         comb(i+1,target-nums[i],nums,temp);
    //         temp.pop_back();
    //     }
    //     // not picking an element on particular index
    //     comb(i+1,target,nums,temp);
    // }


    // vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
    //     vector<int> temp;
    //     vector<vector<int>> res;
    //     sort(nums.begin(),nums.end());
    //     comb(0,target,nums,temp);
    //     for(auto i: ans)
    //        res.push_back(i);
    //     return res;
    // }

    // Optimal Approach 
    
    vector<vector<int>> ans;
    
    void comb(int ind, int target, vector<int> &nums, vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
              continue;
            if(target<nums[i])
              break;
            temp.push_back(nums[i]);
            comb(i+1,target-nums[i],nums,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        vector<int> temp;
        comb(0,target,nums,temp);
        return ans;

    }
};