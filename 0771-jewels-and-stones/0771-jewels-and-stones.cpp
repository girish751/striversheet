class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>cnt;
        for(auto u:stones){
            cnt[u]++;
        }
        int sum=0;
        for(auto u:jewels){
            sum+=cnt[u];
        }
        return sum;
    }
};