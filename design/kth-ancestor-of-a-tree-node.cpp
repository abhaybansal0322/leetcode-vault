class TreeAncestor {
    vector<vector<int>> table;
    int rows,cols;
public:
    TreeAncestor(int n, vector<int>& parent) {
        
        rows = n;
        cols = log2(n)+1;

        table.resize(rows,vector<int>(cols,-1));

        for(int node = 0;node<rows;node++) {
            table[node][0] = parent[node];
        }

        for(int j=1;j<cols;j++) {
            for(int node=0;node<rows;node++) {

                if(table[node][j-1]!=-1) {
                    table[node][j] = table[table[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<cols;j++) {

            if(k & (1<<j)) {
                node = table[node][j];
            }

            if(node == -1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */