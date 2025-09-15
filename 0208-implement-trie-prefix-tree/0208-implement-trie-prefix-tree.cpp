// Node structure representing each character in the Trie
struct Node {
    Node* links[26];  // Pointers to next characters (a-z)
    bool flag = false; // Marks if this node is the end of a word

    // Check if current node has a link for a character
    bool containKey(char ch) { return (links[ch - 'a'] != NULL); }

    // Create/assign a link for a character
    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    // Get the next node corresponding to a character
    Node* get(char ch) { return links[ch - 'a']; }

    // Mark this node as the end of a word
    void setEnd() { flag = true; }

    // Check if this node is marked as the end of a word
    bool isEnd() { return flag; }
};

// Trie class
class Trie {
private:
    Node* root; // Root node of the Trie

public:
    // Constructor: initializes an empty root node
    Trie() { root = new Node(); }

    // Insert a word into the Trie
    void insert(string word) {
        Node* node = root;
        for (auto ch : word) {
            // If link for this character doesn’t exist, create it
            if (!node->containKey(ch)) {
                node->put(ch, new Node());
            }
            // Move to the next node (character)
            node = node->get(ch);
        }
        // After inserting all characters, mark end of word
        node->setEnd();
    }

    // Search if a word exists in the Trie
    bool search(string word) {
        Node* node = root;
        for (auto ch : word) {
            // If at any point the link doesn’t exist → word not present
            if (!node->containKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        // Return true only if the word ends at this node
        return node->isEnd();
    }

    // Check if there exists any word in Trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (auto ch : prefix) {
            // If link missing → prefix not found
            if (!node->containKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        // If we traversed successfully → prefix exists
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */