class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        
        // Greedy loop: remove previous digits if they are larger than current
        for(char c : num){
            while(!s.empty() && k > 0 && s.top() > c){
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        // If k > 0, remove remaining digits from the end
        while(k > 0 && !s.empty()){
            s.pop();
            k--;
        }
        
        // Build the result string from stack
        string ans;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // Remove leading zeros
        int p = 0;
        while(p < ans.size() && ans[p] == '0'){
            p++;
        }
        
        // Create substring from the first non-zero digit
        ans = ans.substr(p);
        
        // Return "0" if the string is empty
        if(ans.empty()){
            return "0";
        }
        
        return ans;
    }
};