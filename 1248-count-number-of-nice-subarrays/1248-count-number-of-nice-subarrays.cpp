class Solution {
    int subarray(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        int l=0;
        int sum=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=subarray(nums,k)-subarray(nums,k-1);
        return ans;
    }
};