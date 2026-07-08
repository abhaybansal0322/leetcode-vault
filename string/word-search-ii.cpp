// class Solution {
//     vector<string> result;
//     int r,c;
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

//     struct trieNode {
//         bool endWord;
//         trieNode* children[26];
//         string word;
//     };

//     trieNode* getNode()
//     {
//         trieNode* temp = new trieNode();
//         temp->endWord = false;
//         for(int i=0;i<26;i++)
//         {
//             temp->children[i] = NULL;
//         }
//         temp->word = "";

//         return temp;
//     }

//     void insert(string str , trieNode* root)
//     {
//         trieNode *temp = root;
//         for(char ch : str)
//         {
//             if(temp->children[ch-'a']==NULL)
//             {
//                 temp->children[ch-'a'] = getNode();
//             }
//             temp = temp->children[ch-'a'];
//         }

//         temp->endWord = true;
//         temp->word = str;
//     }

//     void DFS(vector<vector<char>>& board,int i,int j,trieNode* root)
//     {
//         if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='$' || root->children[board[i][j]-'a']==NULL)
//             return;

//         root = root->children[board[i][j]-'a'];
//         if(root->endWord)
//         {
//             result.push_back(root->word);
//             root->endWord = false;
//         }
//         char temp = board[i][j];
//         board[i][j] = '$';

//         for(vector<int>& dir : directions)
//         {
//             int new_i = i + dir[0];
//             int new_j = j + dir[1];

//             DFS(board,new_i,new_j,root);
//         }

//         board[i][j] = temp;

//     }


// public:
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         r = board.size();
//         c = board[0].size();

//         trieNode* root = getNode();

//         for(string word : words)
//         {
//             insert(word,root);
//         }

//         for(int i=0;i<r;i++)
//         {
//             for(int j=0;j<c;j++)
//             {
//                 char ch = board[i][j];
//                 DFS(board,i,j,root);
//             }
//         }
        
//         return result;
//     }
// };

class Solution {
    
    struct trieNode {

        bool isEnd;
        trieNode* children[26];
        string Word;
    };

    trieNode* getNode() {

        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for(int i=0;i<26;i++)
            newNode->children[i]=NULL;
        
        newNode->Word = "";

        return newNode;
    }

    vector<string> results;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;

    void Insert(string word,trieNode* root) {

        trieNode* crawl = root;

        for(auto& ch : word) {

            int idx = ch - 'a';

            if(!crawl->children[idx])   crawl->children[idx] = getNode();

            crawl = crawl->children[idx];
        }

        crawl->isEnd = true;
        crawl->Word = word;
        
    }

    void DFS(int i,int j,vector<vector<char>>& board,trieNode* root) {

        if(i<0 || j<0 || i>m-1 || j>n-1 || board[i][j]=='$' || !root->children[board[i][j]-'a'])   return;

        root = root->children[board[i][j]-'a'];

        if(root->isEnd) {

            results.push_back(root->Word);
            root->isEnd = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for(auto& dir : directions) {

            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(i_,j_,board,root);
        }

        board[i][j]=temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trieNode* root = getNode();
        m = board.size();
        n = board[0].size();

        for(auto& word : words) {

            Insert(word,root);
        }

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++) {
                
                DFS(i,j,board,root);

            }
        }

        return results;
    }
};