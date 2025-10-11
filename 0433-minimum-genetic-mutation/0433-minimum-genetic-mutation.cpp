class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({startGene,0});
        unordered_map<string,int>cnt;
        for(auto u:bank)  cnt[u]++;
        while(!q.empty()){
            auto s=q.front().first;
            auto val=q.front().second;
            q.pop();
            if(s==endGene) return val;
            for(int i=0;i<s.size();i++){
                char ch=s[i];
                for(char chh='A';chh<='Z';chh++){
                    s[i]=chh;
                    if(cnt.count(s)){
                        q.push({s,val+1});
                        cnt.erase(s);
                    }
                }
                s[i]=ch;
            }
        }
        return -1;
    }
};