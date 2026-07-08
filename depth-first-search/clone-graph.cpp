/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*

    we can either use DFS or BFS for traversal and can either use vector ormap to store addresees . 
    In this case values are given between 1-100 so vector can be used also but map is for genral all values.

*/

class Solution {
    unordered_map<Node*,Node*> mp;

    void DFS(Node* node, Node* cloneNode) {

        for(Node* n : node->neighbors) {

            if(mp.find(n) == mp.end()) {

                Node* newNode = new Node(n->val);
                mp[n] = newNode;
                cloneNode->neighbors.push_back(newNode);
                DFS(n,newNode);
            }

            else {

                cloneNode->neighbors.push_back(mp[n]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {

        if(!node)
            return NULL;

        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;
        DFS(node,cloneNode);
        
        return cloneNode;

    }
};