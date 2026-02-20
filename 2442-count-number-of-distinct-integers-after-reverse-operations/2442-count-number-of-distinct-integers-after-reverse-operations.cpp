class Solution {
public:
    int rev(int n) {
    int x=0;
    while (n) {
        x=x*10+n%10;
        n/=10;
    }
    return x;
}

int countDistinctIntegers(vector<int>& nums) {
    //1 <= nums[i] <= 10^6 , i.e. max value is 1000000 ,
    //and even in reverse it's 999999 as rev of 1000000 is 1 and less than it is 6 digit with max can be 999999

    vector<bool> counted(1000001,false);
    int res=0;
    for (int i : nums) {
        if (counted[i]==false) {
            res++;
            counted[i]=true;
        }
        int x=rev(i);
        if (counted[x]==false) {
            res++;
            counted[x]=true;
        }
    }
    return res;
}
};