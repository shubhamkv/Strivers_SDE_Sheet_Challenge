class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int l=0,r=n-1,mid;

        if(n==1)
          return nums[0];

        while(l<=r)
        {
            mid = l+(r-l)/2;
            if((mid==0 && nums[mid]!=nums[mid+1]) || (mid==n-1 && nums[mid]!=nums[mid-1]) || (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]))
                  return nums[mid];
            else if(nums[mid]!=nums[mid+1])
            {
                if(mid%2!=0)
                   l=mid+1;
                else
                   r=mid-1;
            }
            else
            {
                if(mid%2==0)
                   l=mid+1;
                else
                   r=mid-1;
            }
        }
        return nums[0];
    }
};