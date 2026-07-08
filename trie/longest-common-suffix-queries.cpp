class Solution {
    struct trieNode {
        int idx;
        trieNode* children[26];
        ~trieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    trieNode* getNode(int idx) {

            trieNode* newNode = new trieNode();
            newNode->idx = idx;
            for(int i=0;i<26;i++) {
                newNode->children[i] = NULL;
            }

            return newNode;
        }

        int searchTrie(trieNode* root, string& word) {
            int res = root->idx;
            int n = word.length();

            for(int i=n-1;i>=0;i--) {

                int chIdx = word[i]-'a';
                root = root->children[chIdx];
                if(!root) return res;

                res = root->idx;
            }

            return res;
        }

        void insertTrie(trieNode* root,int i, vector<string>& wordsContainer) {

            string word = wordsContainer[i];
            int n = word.length();

            for(int j=n-1;j>=0;j--) {

                int chIdx = word[j]-'a';
                if(root->children[chIdx] == NULL) {
                    root->children[chIdx] = getNode(i);
                }
                root = root->children[chIdx];

                if(wordsContainer[root->idx].length() > n) {
                    root->idx = i;
                }
            }
        }
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        int m = wordsContainer.size();
        int n = wordsQuery.size();
        vector<int> result(n);

        trieNode* root = getNode(0);

        for(int i=0; i<m; i++) {
            int idx = root->idx;
            if(wordsContainer[idx].length() > wordsContainer[i].length()) {
                root->idx = i;
            }
            insertTrie(root,i,wordsContainer);
        }

        for(int i=0; i<n; i++) {

            result[i] = searchTrie(root,wordsQuery[i]);
        }

        delete root;
        return result;
    }
};