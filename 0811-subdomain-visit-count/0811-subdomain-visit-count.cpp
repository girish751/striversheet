class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;

        unordered_map<string, int> frq;
        int n = cpdomains.size();
        for(int j=0;j<n;j++){
            string s = cpdomains[j];

            int i = 0, rep =0;
            while(s[i] != ' '){
                rep = rep*10 + (s[i] - '0');
                i++;
            }
            i++;
             s = s.substr(i);
            cout << s << endl;
            i = 0;
            while(i < s.length()){
                frq[s] += rep;
                while(i<s.length() && s[i] != '.'){
                    // temp.push_back(s[i]);
                    i++;
                }
                if(i < s.length()){
                     s = s.substr(i+1);
                     i = 0;
                }
               
            }
        }

        for(auto p:frq){
            string t = to_string(p.second);
            
            string s = p.first;
            ans.push_back(t+ ' ' + s);

        }
        return ans;
    }
};