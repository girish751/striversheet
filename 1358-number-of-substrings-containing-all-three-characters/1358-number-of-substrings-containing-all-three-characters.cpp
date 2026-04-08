class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;
        int l=0;
        int cnt=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(mp.size()>=3){
                 cnt+=s.length()-r;
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;

            }
          
        }
        return cnt;
    }
};