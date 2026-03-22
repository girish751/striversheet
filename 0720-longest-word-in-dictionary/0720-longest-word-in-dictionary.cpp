class Node {
public:
    unordered_map<char,Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }

};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(vector<string> words) {
        for (string word : words) {
            Node* temp = root;
            for (char ch : word) {
                if (!temp->children.count(ch)) temp->children[ch] = new Node();
                temp = temp->children[ch];
            }
            temp->endOfWord = true;
        }
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        trie.insert(words);

        string ans = "";

        for (string word : words) {
            bool isValid = true;
            Node* temp = trie.root;
            for (char ch : word) {
                temp = temp->children[ch];
                if (!temp->endOfWord) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                if (ans.length()<word.length()) ans = word;
                else if (ans.length() == word.length() && ans>word) ans = word;
            } 
        }
        return ans;
    }
};