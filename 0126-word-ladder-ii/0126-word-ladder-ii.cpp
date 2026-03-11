class Solution {
    vector<vector<string>> ans;
    string b;
public:

    void dfs(unordered_map<string,int> mapping , string word , vector<string> seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }

        int step = mapping[word];
        for(int i = 0;i<word.size();i++){
            string temp = word;
            for(char c='a';c<='z';c++){
                temp[i] = c;
                if(mapping.find(temp) != mapping.end() && mapping[temp] +1 == step){
                    seq.push_back(temp);
                    dfs(mapping ,temp,seq );
                    seq.pop_back();
                }
            }
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> wordset;
        b = beginWord;
        for(auto &c:wordList){
            wordset[c]++;
        }

        if(wordset.find(endWord) == wordset.end()){
            return {};
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_map<string,int> mapping;
        mapping[beginWord] =1;

        int mini = INT_MAX;
        wordset.erase(beginWord);

        while(!q.empty()){
            auto [word,step] = q.front();
            q.pop();

            for(int i = 0;i<word.size();i++){
                string temp = word;
                for(char c='a';c<='z';c++){
                    temp[i] = c;

                    if(temp == endWord ){
                        mini = min(mini , step+1);
                    }

                    if(wordset.find(temp) != wordset.end()){
                        mapping[temp] = step+1;
                        q.push({temp,step+1});
                        wordset.erase(temp);
                    }
                }
            }
        }

        if(mapping.find(endWord)!= mapping.end() ){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(mapping , endWord, seq);
        }

        return ans;
    }
};