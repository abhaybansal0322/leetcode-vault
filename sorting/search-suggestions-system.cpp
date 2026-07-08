class Solution {
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> children;

        TrieNode()
        {
            isWord = false;
            children = vector<TrieNode*>(26,nullptr);
        }
    };

    void dfs(TrieNode* node,string& prefix,vector<string>& result)
    {
        if(result.size()==3 || !node)
        {
            return;
        }
        if(node->isWord)
        {
            result.push_back(prefix);
        }

        TrieNode* temp = node;
        for(char ch = 'a';ch<= 'z';ch++)
        {
            int idx = ch-'a';
            if(temp->children[idx])
            {
                prefix.push_back(ch);
                dfs(temp->children[idx],prefix,result);
                prefix.pop_back();
            }
        }
    }

    vector<string> getSuggested(string &prefix,TrieNode* root)
    {
        TrieNode* node = root;
        vector<string> result;
        for(char& ch : prefix)
        {
            int idx = ch-'a';
            if(node->children[idx]==NULL)
            {
                return result;
            }
            node = node->children[idx];
        }

        dfs(node,prefix,result);
        return result;
    }

    void insertWords(string &word,TrieNode* root)
    {
        // if(root==NULL) {return;}
        TrieNode* node = root;

        for(char& c : word)
        {
            int idx = c-'a';
            if(node->children[idx]==nullptr)
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx]; 
        }
        node->isWord = true;
    }


public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        vector<vector<string>> ans;


        for(string& product : products)
        {
            insertWords(product,root);
        }

        string prefix="";
        for(char& ch : searchWord)
        {
            prefix += ch;
            vector<string> sugg = getSuggested(prefix,root);
            ans.push_back(sugg);
        }

        return ans;
        
    }
};