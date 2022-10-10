struct Node {
    Node* childs[26];
    bool isWord = false;
    
    bool containsKey(char ch){
        return childs[ch - 'a'];
    }
    
    void putChar(char ch, Node* node){
        childs[ch - 'a'] = node;
    }
    
    Node* getNode(char ch){
        return childs[ch - 'a'];
    }  
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(auto i: word){
            if(!tmp->containsKey(i)){
                tmp->putChar(i, new Node());
            }
            tmp = tmp->getNode(i);
        }
        tmp->isWord = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(auto i: word){
            if(!tmp->containsKey(i)){
                return false;
            }
            tmp = tmp->getNode(i);
        }
        return tmp->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(auto i: prefix){
            if(!tmp->containsKey(i)){
                return false;
            }
            tmp = tmp->getNode(i);
        }
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