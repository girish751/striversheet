class Solution {
public:
    int calculate(vector<int>&nums,int start)
    {
        int n = nums.size();
        int operations = 0;
        for(int i =start;i<n;i+=2)
        {
            int curr = nums[i];
            int left = 1e9,right = 1e9;
            if(i-1>=0)left = nums[i-1];
            if(i+1<n)right = nums[i+1];
            if(curr<left && curr<right)continue;
            else operations += (curr - min(left,right) + 1);
        }
        return operations;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(calculate(nums,0),calculate(nums,1));
    }
};