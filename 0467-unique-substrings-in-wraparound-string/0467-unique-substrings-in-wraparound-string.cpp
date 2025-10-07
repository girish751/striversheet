class Solution {
public:

    int func(char c, string s){
        int n = s.length();
        int mx = 0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                int cnt = 1;
                int start = s[i]-'a';
                if(start==25){ /*note: for 'z'->'a' tansition, 
we can keep z = -1 so that it's consecutive with 'a' as 'a' = 0;*/
                    start = -1;
                }
                int j = i+1;
                for(j=i+1;j<n;j++){
                    int next = s[j]-'a';
                    if(start == 25){
                        start = -1;
                    }
                    if(next-start!=1){
                        break;
                    }
                    else{
                        cnt++;
                    }
                    start = next;
                }
                i = j-1;
                mx = max(mx,cnt);
            }
        }
        return mx;
    }
    int findSubstringInWraproundString(string s) {
        int ans = 0;
        for(char c = 'a';c<='z';c++){
            ans+=func(c,s);
        }
        return ans;
    }
};