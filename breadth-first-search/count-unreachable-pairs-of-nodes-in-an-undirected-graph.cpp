class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        
        return parent[i];
    }
    
    void Union(int x, int y, vector<long long>& sizeOfComp) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
                sizeOfComp[p_x] += sizeOfComp[p_y]; // Merge size
                sizeOfComp[p_y] = 0; // Reset merged size
            } 
            else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
                sizeOfComp[p_y] += sizeOfComp[p_x]; // Merge size
                sizeOfComp[p_x] = 0; // Reset merged size
            } 
            else {
                parent[p_x] = p_y;
                sizeOfComp[p_y] += sizeOfComp[p_x]; // Merge size
                sizeOfComp[p_x] = 0; // Reset merged size
                rank[p_y]++;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        vector<long long> sizeOfComp(n, 1); // Each node is its own component initially

        // Initialize DSU
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Process edges
        for(auto &edge : edges) {
            int x = edge[0];
            int y = edge[1];

            if(find(x) != find(y)) {
                Union(x, y, sizeOfComp);
            }
        }

        // Get sizes of connected components
        vector<long long> componentSizes;
        for(int i = 0; i < n; i++) {
            if(parent[i] == i && sizeOfComp[i] > 0) { // Only consider root parents
                componentSizes.push_back(sizeOfComp[i]);
            }
        }

        // Calculate number of unreachable pairs
        long long ans = 0, sum = 0;
        for(long long size : componentSizes) {
            // ans += sum * size; // Count pairs formed with previously counted nodes
            // sum += size;

            ans += size*(n-size);
            n -= size;
        }

        return ans;
    }
};
