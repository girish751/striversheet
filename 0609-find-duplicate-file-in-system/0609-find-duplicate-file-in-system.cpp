class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>map;
        int n = paths.size();
        for(int i=0;i<n;i++){
            string dir = paths[i];
            stringstream ss(dir);
            string file;
            int s=0;
            string base = "";
            while(ss >> file){
                // ss >> word reads each word separated by whitespace.
                if(s==0){
                    base = file;
                    s++;
                }
                else{
                    int l = file.length();
                    bool flag = false; // openbracket
                    string content = "";
                    string name = "";
                    for(int i=0;i<l;i++){
                        if(file[i]=='('){
                            flag = true;
                            continue;
                        }
                        if(!flag){
                            name += file[i];
                        }   
                        if(flag){
                            if(file[i]!=')'){
                                content += file[i];
                            }
                        }
                    }

                    string path = base + "/" + name;
                    map[content].push_back(path);
                }
            }
        }

        auto it = map.begin();
        vector<vector<string>>ans;
        while(it!=map.end()){
            if((*it).second.size()>=2){
                ans.push_back((*it).second);
            }
            ++it;
        }
        return ans;
    }
};