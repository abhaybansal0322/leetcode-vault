class Solution {
private:
    // Helper structure for Union-Find
    struct UnionFind {
        vector<int> parent;
        vector<int> size;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;  // Initially, each node is its own parent
            }
        }

        // Find with path compression
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);  // Path compression
            }
            return parent[x];
        }

        // Union by size (union the smaller tree under the bigger tree)
        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    };

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);

        // Sliding window to group nodes
        int j = 0;
        for (int i = 0; i < n; ++i) {
            // While nums[j] - nums[i] <= maxDiff, union nodes
            while (j < n && nums[j] - nums[i] <= maxDiff) {
                uf.unionSets(i, j);
                ++j;
            }
        }

        // Answer the queries
        vector<bool> result;
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            // If the roots of u and v are the same, they are connected
            result.push_back(uf.find(u) == uf.find(v));
        }

        return result;
    }
};
