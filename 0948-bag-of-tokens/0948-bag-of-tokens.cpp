class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
           
           int n = tokens.size();
        int start=0 , end = n-1 , maxscore=0 , score=0;
        while(start<=end)
        {
            if(power >= tokens[start])
            {
                power -= tokens[start];
                score++;
                start+=1;
                maxscore = max(maxscore,score);
            }
           else if (score>=1)
           {
            power+= tokens[end];
            end--;
            score--;
           }
           else return maxscore;
        }
        return maxscore;
    }
};