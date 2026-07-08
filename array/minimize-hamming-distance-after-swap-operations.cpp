class Solution {

    struct DSU {

        vector<int> parent,rank;
        DSU(int n) {

            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++) parent[i] = i;
        }

        int find(int i) {

            if(parent[i] == i) return i;

            return parent[i] = find(parent[i]);
        }

        void Union(int i,int j) {

            int pi = find(i);
            int pj = find(j);

            if(pi != pj) {

                if(rank[pi] < rank[pj]) swap(pi,pj);

                parent[pj] = pi;
                rank[pi] += rank[pj];
            }
        }
    };
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        DSU dsu(n);

        for(auto X : allowedSwaps) {

            dsu.Union(X[0],X[1]);
        }

        unordered_map<int,vector<int>> groups;
        int ans = 0;
        for(int i=0;i<n;i++) {

            groups[dsu.find(i)].push_back(i);
        }

        for(auto g : groups) {

            unordered_map<int,int> freq;
            for(int idx : g.second) {
                freq[source[idx]]++;
            }

            for(int idx : g.second) {
                if(freq[target[idx]]>0)
                    freq[target[idx]]--;
                else ans ++;
            }
        }
        return ans;
    }
};