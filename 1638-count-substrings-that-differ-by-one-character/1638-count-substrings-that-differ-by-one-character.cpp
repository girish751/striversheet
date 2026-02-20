class TrieNode{
    public:
        TrieNode* children[26];
        int terminatingCount;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            terminatingCount=0;
        }
};
class Solution {
private:
    // inserting the word in the trie.
    void insertWord(TrieNode* root,string s){
        if(s==""){
            root->terminatingCount+=1;
            return;
        }
        char x=s.front();
        if(!((root->children)[x-'a'])){
            TrieNode* newNode=new TrieNode();
            root->children[x-'a']=newNode;
        }
        root=root->children[x-'a'];
        insertWord(root,s.substr(1));
    }
    int check(TrieNode* root,string s,int cnt){
        if(cnt==2){
            // if we have replaced more than 1 character just return 0
            return 0;
        }
        if(s==""){
            if(cnt==1){
                // reaching the end if we have only replaced 1 char then return the number of substrings ending at current node.
                return root->terminatingCount;
            }
            // else return 0 as we have to replace only 1 character.
            return 0;
        }
        char x=s.front();
        int ans=0;
        for(int i=0;i<26;i++){
           if(root->children[i]){
               if(i==x-'a'){
                   // not replacing current character
                   ans=ans+(check(root->children[i],s.substr(1),cnt));
               }
               else{
                   // replacing current character
                   ans=ans+(check(root->children[i],s.substr(1),cnt+1));
               }
           }
        }
        return ans;
    }
public:
    int countSubstrings(string s, string t) {
        ios_base::sync_with_stdio(false);
        TrieNode* root=new TrieNode();
        int ans=0;

        // inserting every substring of t in trie.
        for(int i=0;i<t.length();i++){
            string str="";
            for(int j=i;j<t.length();j++){
                str.push_back(t[j]);
                insertWord(root,str);
            }
        }

        // calculating ans
        for(int i=0;i<s.length();i++){
            string str="";
            for(int j=i;j<s.length();j++){
                str.push_back(s[j]);
                if(str.length()<=t.length()){
                    int res=check(root,str,0);
                    ans=ans+res;
                }
            }
        }
        return ans;
    }
};