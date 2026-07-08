struct trieNode {

    trieNode* left;
    trieNode* right;
    trieNode() {
        right = left = NULL;
    }
};

class trie {
    trieNode* root;

    public:
    trie() {
        root = new trieNode();
    }

    void insert(int num) {
        
        trieNode* curr = root;
        for(int i=31;i>=0;i--) {

            int bit = (num>>i)&1;

            if(bit == 0) {

                if(curr->left == NULL) {

                    curr->left = new trieNode();
                }
                curr =curr->left;
            }

            if(bit == 1) {

                if(curr->right == NULL) {

                    curr->right = new trieNode();
                }
                curr =curr->right;
            }
        }
    }

    int getMax(int num) {

        trieNode* curr = root;
        int ans = 0;

        for(int i=31;i>=0;i--) {

            int bit = (num>>i)&1;

            if(bit == 0) {

                if(curr->right) {

                    ans |= (1<<i);
                    curr = curr->right;
                } else {
                    curr = curr->left; 
                }
            }

            if(bit == 1) {

                if(curr->left) {

                    ans |= (1<<i);
                    curr = curr->left;
                } else {
                    curr = curr->right; 
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        trie T;

        for(int num : nums) {
            T.insert(num);
        }

        int ans = 0;

        for(int num : nums) {
            ans = max(ans, T.getMax(num));
        }

        return ans;
    }
};