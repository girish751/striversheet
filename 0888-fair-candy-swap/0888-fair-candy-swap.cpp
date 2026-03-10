class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) 
    {
        int n=aliceSizes.size();
        int m=bobSizes.size();
        int i=0,j=0,bcnt=0,acnt=0;
        while(i<n||j<m)
        {
            if(i<n&&j<m)
            {
                bcnt+=bobSizes[j];
                acnt+=aliceSizes[i];
                j++;
                i++;
            }
            else if(i<n)
            {
                acnt+=aliceSizes[i];      
                i++;     
            }
            else
            {
                bcnt+=bobSizes[j];
                j++;
            }
        }
        int dif=acnt-bcnt;
        dif=dif/2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(aliceSizes[i]-bobSizes[j]==dif)
                {
                    return {aliceSizes[i],bobSizes[j]};
                }
            }
        }
        return{};
    }
//please upvote...
};