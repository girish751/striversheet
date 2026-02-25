class Solution {
public:
    bool fun(int index,long long int prev1,long long int prev2, string &num)
    {
        int n = num.size();
        if(index == n-1)
        {
            if(prev1 == -1 || prev2 == -1)
            {
                return false;
            }
            if(prev1+prev2 == (num[n-1]-'0'))
            {
                return true;
            }
            return false;
        }

        if(num[index] == '0')
        {
            // take as a single digit
            if(prev1 == -1)
            {
                return fun(index+1,0,prev2,num);
            }
            else if(prev2 == -1)
            {
                return fun(index+1,prev1,0,num);
            }
            else if(prev1+prev2 == 0ll)
            {
                return fun(index+1,prev2,0,num);
            }
            return false;
        }

        bool ans = false;

        // make current number
        int limit = min(index+18,int(n));
        for(int i=index;i<limit;i++)
        {
            long long int next = 0;
            // index to i
            int j = index;
            while(j<=i){
                next *= 10;
                next += (num[j]-'0');
                j++;
            }
            
            if(prev1 == -1)
            {
                if(i+1 == n)return false;
                else ans = fun(i+1,next,prev2,num);
            }
            else if(prev2 == -1)
            {
                if(i+1 == n)return false;
                else ans = fun(i+1,prev1,next,num);
            }
            else if(prev1+prev2 == next)
            {
                if(i+1 == n)return true;
                else ans = fun(i+1,prev2,next,num);
            }
            if(ans)return true;
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        return fun(0,-1,-1,num);
    }
};