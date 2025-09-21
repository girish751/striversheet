class Solution {
public:
    int dp[300005][31];
    bool f(vector<int>&nums,int mask,int sum,int totalsum){
        int len = __builtin_popcount(mask);
        if(dp[sum][len]!=-1) return dp[sum][len];
        double avg1 = (double)sum/len;
        double avg2 = (double)(totalsum-sum)/(nums.size()-len);
        if(avg1==avg2) return true;
        bool ans = false;
        for(int i=0;i<nums.size();i++){
            if((mask & (1<<i))!=0) continue;
            ans = ans | f(nums,mask | (1<<i),sum+nums[i],totalsum);
        }
        return dp[sum][len] = ans;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = 0;
        for(auto ele:nums){
            sum += ele;
        }
        memset(dp,-1,sizeof(dp));
        return f(nums,0,0,sum);
    }
};