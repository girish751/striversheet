class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
       int start = -1;
       int end = -1;
       int max_so_far = nums[0];
       for(int i = 1; i< nums.size(); i++) {
           if(nums[i] >= max_so_far) {
            max_so_far = nums[i];
           } else {
            end = i;
           }
       }
        int min_so_far = nums[n - 1];
        for(int i =n-2; i >= 0; i--) {
            if(nums[i] <= min_so_far) {
                min_so_far = nums[i];
            } else {
                start = i;
            }
        }
        if(start == -1) return 0;
        return end - start +1;
    }
};