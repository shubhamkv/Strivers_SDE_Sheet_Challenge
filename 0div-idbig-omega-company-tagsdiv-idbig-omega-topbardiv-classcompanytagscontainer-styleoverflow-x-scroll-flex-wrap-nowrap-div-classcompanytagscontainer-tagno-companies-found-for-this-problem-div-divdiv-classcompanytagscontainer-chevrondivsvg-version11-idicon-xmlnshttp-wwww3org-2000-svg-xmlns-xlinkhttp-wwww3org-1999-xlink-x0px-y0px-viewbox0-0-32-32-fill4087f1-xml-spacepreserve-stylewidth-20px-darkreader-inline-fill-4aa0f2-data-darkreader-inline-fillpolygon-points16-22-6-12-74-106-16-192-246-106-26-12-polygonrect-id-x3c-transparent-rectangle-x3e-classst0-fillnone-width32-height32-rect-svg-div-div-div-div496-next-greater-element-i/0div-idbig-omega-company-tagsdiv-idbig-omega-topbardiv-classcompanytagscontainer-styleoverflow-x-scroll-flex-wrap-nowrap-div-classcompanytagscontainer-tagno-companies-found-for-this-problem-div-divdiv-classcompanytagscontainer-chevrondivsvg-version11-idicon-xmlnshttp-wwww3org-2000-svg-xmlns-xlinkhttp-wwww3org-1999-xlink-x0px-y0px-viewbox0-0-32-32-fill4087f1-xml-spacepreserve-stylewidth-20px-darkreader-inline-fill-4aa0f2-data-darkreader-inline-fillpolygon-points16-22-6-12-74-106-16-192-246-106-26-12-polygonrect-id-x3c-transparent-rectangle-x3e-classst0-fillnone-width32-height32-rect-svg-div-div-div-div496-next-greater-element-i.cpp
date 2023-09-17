class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
       

        // ------------------------- brute force approach --------------

        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(nums2[j]==nums1[i])
        //         {
        //             int x=-1;
        //             for(int k=j;k<nums2.size();k++)
        //             {
        //                 if(nums2[k]>nums1[i])
        //                 {
        //                     x=nums2[k];
        //                     break;
        //                 }
        //             }
        //             ans.push_back(x);
        //         }
        //     }
        // }
        // return ans;

        // ------------------------------------------------------------------------
        
        // ---------------------------- Optimal Approach --------------------------

        // Using map and stack data structure 

        stack<int> s;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=m-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<nums2[i])
            {
                s.pop();
            }
            if(s.empty())
              mp[nums2[i]]=-1;
            else
              mp[nums2[i]]=s.top();

            s.push(nums2[i]);
        }
        for(int j=0;j<n;j++)
        {
            ans.push_back(mp[nums1[j]]);
        }
        return ans;
    }

};