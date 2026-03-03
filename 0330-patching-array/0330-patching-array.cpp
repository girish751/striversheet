class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
       long long int i=0,till=0, tillc=0;
        while(till<n){
            if(i<nums.size()&&till>=nums[i]-1){
                till+=nums[i];
                i++;
            }else{
                till+=(till+1);
                tillc++;
            }
        }
        return tillc;
    }
};