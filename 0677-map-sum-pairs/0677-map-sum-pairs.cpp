class Node{
public:
    Node* nodes[26];
    bool isLeaf=false;
    int val=0;
    Node(int v){
        isLeaf=false;
        val+=v;
        for(int i=0;i<26;i++){nodes[i]=nullptr;}
    }
    bool containsKey(char c){return nodes[char(c)-char('a')]!=nullptr;}
    void insertKeyValue(char c,int x){
        if(nodes[char(c)-char('a')]){nodes[char(c)-char('a')]->val+=x;return;}
        nodes[char(c)-char('a')]=new Node(x);}
    Node* getNode(char c){return nodes[char(c)-char('a')];}
    int getValue(){return val;}
};
class Trie{
public:
    Node* root;
    Trie(){
        root= new Node(0);
    }
    void insert(string key,int val,int og){
        Node* node=root;
        for(auto i:key){
            node->insertKeyValue(i,-og+val);
            node=node->getNode(i);
        }
    }
    int sum(string prefix){
        Node* node=root;
        for(auto i:prefix){
            if(!node->containsKey(i)){return 0;}
            node=node->getNode(i);
        }
        return node->val;
    }
};
class MapSum {
public:
    Trie* root;
    unordered_map<string,int> mp;
    MapSum() {
        root=new Trie();
        unordered_map<string,int> mpt;
        mp=mpt;
    }
    
    void insert(string key, int val) {
        root->insert(key,val,mp[key]);
        mp[key]=val;
    }
    
    int sum(string prefix) {
        return root->sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */