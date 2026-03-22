class Solution {
public:

    string to_repeat(int rep,int &i, string s){
        string ans = "";
        if(i >= s.size()){
            return ans;
        }
        while(s[i] != ']'){ 
            if(isdigit(s[i])){
                string num = "";
                num += s[i];
                while(s[++i] != '['){
                    num += s[i];
                }
                int repeat = stoi(num);
                i++;
                ans += to_repeat(repeat, i, s);
            }else{
                ans += s[i];
                i++;
            }
        }
        i++;
        string to_be = ans;
        for(int i=1 ; i<rep ; i++){
            ans += to_be;
        }
        return ans;

    }

    string decodeString(string s) {
        string ans = "";
        int i=0;
        while(i < s.size()){
            if(isdigit(s[i])){
                string num = "";
                num+=s[i];
                while(s[++i] != '['){
                    num += s[i];
                }
                int repeat = stoi(num);
                i++;
                ans += to_repeat(repeat, i, s);
            }else{
                ans+= s[i];
                i++;
            }
        }

        return ans;
    }
};