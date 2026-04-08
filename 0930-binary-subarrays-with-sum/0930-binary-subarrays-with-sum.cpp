class Solution {
    int subarray(vector<int>&nums,int goal){
        if(goal<0){
            return 0;
        }
        int l=0;
        int sum=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=subarray(nums,goal)-subarray(nums,goal-1);
        return ans;
    }
};