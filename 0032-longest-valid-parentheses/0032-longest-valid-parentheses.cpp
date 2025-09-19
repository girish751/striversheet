class Solution {
public:

 
    int longestValidParentheses(string str) {
        stack<int> s;
        int n =str.size();
        vector<int> arr(n,0);
        
        for(int i=0;i<n;i++){
            
            if(str[i]=='('){
                s.push(i);
            }else if(s.size()>0){
                int matched_position = s.top();
                s.pop();
                arr[matched_position]=1;
                arr[i]=1;
            }
        }
        
        
        int count =0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count++;
            }else{
                count=0;
            }
            maxi=max(count,maxi);
        }
        
        return maxi;
    }
};