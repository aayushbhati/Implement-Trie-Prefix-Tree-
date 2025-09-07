class Trie {
public:
    struct Node {
        Node* children[26] = {};
        string storedWord = "";
    };

    Node* rootNode;

    Trie() {
        rootNode = new Node();
    }
    
    void insert(string word) {
        Node* current = rootNode;
        for (auto ch : word) {
            if (!current->children[ch - 'a']) {
                current->children[ch - 'a'] = new Node();
            }
            current = current->children[ch - 'a'];
        }
        current->storedWord = word;
    }
    
    bool search(string word) {
        Node* current = rootNode;
        for (auto ch : word) {
            if (!current->children[ch - 'a']) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        return current->storedWord == word;
    }
    
    bool startsWith(string prefix) {
        Node* current = rootNode;
        for (auto ch : prefix) {
            if (!current->children[ch - 'a']) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        return true;
    }
};
