class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        
        int ans=0;
        for(int l = 0; l<n; l++){
            vector<int> letters(26,0);
            for(int r = l; r<n; r++){
                int maxi = INT_MIN;
                int mini = INT_MAX;
                
                letters[s[r]-'a']++; 

                for(int i = 0; i<26; i++){
                    if(letters[i]!=0){
                        maxi = max(maxi, letters[i]);
                        mini = min(mini, letters[i]);
                    } 
                }   
                ans+=(maxi-mini);  
            }
        }
        
        return ans;
    }
};