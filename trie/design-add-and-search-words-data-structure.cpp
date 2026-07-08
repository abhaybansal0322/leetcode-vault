class WordDictionary {
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

    WordDictionary() {
        
        root = getNode();
    }
    
    void addWord(string word) {
        
        trieNode* crawler = root;

        for(int i=0;i<word.length();i++) {

            char ch = word[i];
            int idx = ch - 'a';

            if(!crawler->children[idx]) crawler->children[idx] = getNode();

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }

    bool searchUtil(trieNode* root,string word) {

        trieNode* crawler = root;

        for(int i=0;i<word.length();i++) {

            if(word[i] == '.') {

                for(int j=0;j<26;j++) {

                    if(crawler->children[j]) {

                        if(searchUtil(crawler->children[j],word.substr(i+1)))   return true;
                    }
                    
                }
                return false;
            }

            else {

                int idx = word[i] - 'a';

                if(!crawler->children[idx]) return false;

                crawler = crawler->children[idx];
            }
        }

        return (crawler!=NULL && crawler->isEndOfWord);
    }
    
    bool search(string word) {
        
        return searchUtil(root,word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */