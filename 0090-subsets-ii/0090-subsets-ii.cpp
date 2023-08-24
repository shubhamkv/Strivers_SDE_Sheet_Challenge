class Solution {
public:
    // Brute - fore Approach : Taking extra time for inserting into set and then converting it into 
    //                          list of vector of vector

    // set<vector<int>> ans;
    // void sub(vector<int> &nums, vector<int> &temp, int i)
    // {
    //     if(i==nums.size())
    //     {
    //         ans.insert(temp);
    //         return;
    //     }
        
    //     // take or pick particular index into the subsequence
    //     temp.push_back(nums[i]);
    //     sub(nums,temp,i+1);
    //     temp.pop_back();

    //     // not take or not pick , this element into the subsequence
    //     sub(nums,temp,i+1);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     vector<int> temp;
    //     sort(nums.begin(),nums.end());
    //     sub(nums,temp,0);
    //     for(auto i: ans)
    //        res.push_back(i);
    //     return res;
    // }

    // --------------------------------------------------------------------------------------------
    
    //  Optimal Approach

    vector<vector<int>> ans;

    void sub(int ind, vector<int> &nums, vector<int> &temp) {

        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
               continue;
            temp.push_back(nums[i]);
            sub(i+1,nums,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> temp;
        sort(nums.begin(),nums.end());
        sub(0,nums,temp);
        return ans;
    } 
};