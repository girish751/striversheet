class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>um;
        for(char &ch:s){
            um[ch]++;
        }
        int vres=0;
        int cres=0;
        for(auto &x:um){
            if(x.first=='a' || x.first=='e'|| x.first=='i' ||x.first=='o' ||x.first=='u'){
                if(x.second>=vres){
                    vres=x.second;
                }
            }
            else{
                if(x.second>=cres){
                    cres=x.second;
                }
            }
        }
        return vres+cres;
    }
};