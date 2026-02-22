class Solution {
    void change(int&first,int&second){
        int temp=first;
        first=second;
        second=temp;
    }
public:
    int scoreDifference(vector<int>& nums) {
        // int first_sum=0;
        // int second_sum=0;
        // int active=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]%2!=0){
        //         active=1-active;
        //     }
        //     if(i%6==5){
        //         active=1-active;
        //     }
        //     if(active == 0){
        //       first_sum+=nums[i];
        //      }
        //      else{
        //          second_sum+=nums[i];
        //         }
        //     }
            
        // return first_sum-second_sum;
        int first_sum=0;
        int second_sum=0;
        int first=0;
        int second=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                change(first,second);
                if(i%6==5){
                    change(first,second);
                }
                if(first==0){
                    first_sum=first_sum+nums[i];
                }
                else{
                    second_sum=second_sum+nums[i];
                }
            }
            else{
                if(i%6==5){
                    change(first,second);
                }
                if(first==0){
                    first_sum=first_sum+nums[i];
                }
                else{
                    second_sum=second_sum+nums[i];
                }
            }
        }
         return first_sum-second_sum;
    }
   
};