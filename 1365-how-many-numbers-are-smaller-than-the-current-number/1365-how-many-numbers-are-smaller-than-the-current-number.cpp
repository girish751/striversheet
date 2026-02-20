class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101,0);
        for(int i:nums){
            count[i]++;
        }
        for(int i=1;i<=100;i++){
            count[i] += count[i-1];
        }
        vector<int> ans;
        for(int i:nums){
            ans.push_back(i>0 ? count[i-1] : 0);
        }
        return ans;
    }
};