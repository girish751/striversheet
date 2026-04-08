class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int maxvalue=0;
        int l=0;
        int lsum=0;
        int rsum=0;
        while(l<=k-1){
            lsum+=cardpoints[l];
            l++;
        }
        maxvalue=lsum;
        int r=cardpoints.size()-1;
        for(int l=k-1;l>=0;l--){
            lsum-=cardpoints[l];
            rsum+=cardpoints[r];
            r--;
            maxvalue=max(maxvalue,lsum+rsum);
        }
        return maxvalue;
        
    }
};