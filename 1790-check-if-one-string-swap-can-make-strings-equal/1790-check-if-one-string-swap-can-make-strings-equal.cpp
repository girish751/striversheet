class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int f=-1;int s=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(f!=-1){
                    s=i;
                }else{
                    f=i;
                }
            }
        }
        if(f!=-1&& s!=-1)
        swap(s1[f],s1[s]);
        return s1==s2;
        
    }
};