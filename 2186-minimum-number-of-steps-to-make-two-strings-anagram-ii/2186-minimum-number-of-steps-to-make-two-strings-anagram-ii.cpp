class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>frequency(26, 0);
        int ans = 0;
        for(char ch : s){
            frequency[ch-'a']++;
        }
        for(char ch : t){
            frequency[ch-'a']--;
        }
        for(auto it : frequency){
            ans += abs(it);
        }
        return ans;
    }
};