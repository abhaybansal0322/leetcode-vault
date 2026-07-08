class Trie {
public:

    struct trieNode {

        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {

        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for(int i=0;i<26;i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {

        trieNode* crawler = root;

        for(int i=0;i<word.length();i++) {

            char ch = word[i];
            int idx = ch - 'a';

            if(!crawler->children[idx]) crawler->children[idx] = getNode();

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {

        trieNode* crawler = root;

        for(auto& ch : word) {

            int idx = ch - 'a';

            if(!crawler->children[idx]) return false;

            crawler = crawler->children[idx];
        }

        return (crawler!=NULL && crawler->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for(auto& ch : prefix) {

            int idx = ch - 'a';
            
            if(!crawler->children[idx]) return false;

            crawler = crawler->children[idx];
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