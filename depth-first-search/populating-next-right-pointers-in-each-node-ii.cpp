/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
            
        queue<Node*> Q;
        Q.push(root);

        while(!Q.empty())
        {
            int N = Q.size();
            Node* prev = NULL;

            while(N--)
            {
                Node* curr = Q.front();
                Q.pop();

                if(prev) prev->next = curr;

                if(curr->left) Q.push(curr->left);

                if(curr->right) Q.push(curr->right);

                prev = curr;
            }
        }

        return root;
    }
};