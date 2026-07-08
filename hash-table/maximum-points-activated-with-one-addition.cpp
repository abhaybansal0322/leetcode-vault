class Solution {
    struct DSU {

        vector<int> parent,size;
        DSU(int n) {

            parent.resize(n);
            size.resize(n,1);
            iota(parent.begin(),parent.end(),0);
        }

        int find(int i) {

            if(parent[i] == i) return i;

            return parent[i] = find(parent[i]);
        }

        void Union(int i,int j) {

            int pi = find(i);
            int pj = find(j);

            if(pi != pj) {

                if(size[pi] < size[pj]) {
                    swap(pi,pj);
                }

                parent[pj] = pi;
                size[pi] += size[pj];
            }
        }
    };
public:
    int maxActivated(vector<vector<int>>& points) {
        
        int n = points.size();
        DSU dsu(n);

        vector<pair<int,int>> X,Y;
        X.reserve(n);
        Y.reserve(n);

        for(int i=0;i<n;i++) {

            X.push_back({points[i][0],i});
            Y.push_back({points[i][1],i});
        }

        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());

        for(int i=1;i<n;i++) {

            if(X[i].first == X[i-1].first) {

                dsu.Union(X[i].second,X[i-1].second);
            }
            if(Y[i].first == Y[i-1].first) {

                dsu.Union(Y[i].second,Y[i-1].second);
            }
        }

        vector<int> cmpSize;
        for(int i=0;i<n;i++) {

            if(i == dsu.parent[i]) {

                cmpSize.push_back(dsu.size[i]);
            }
        }

        if(cmpSize.size() == 1) return n+1;

        int max1 = INT_MIN,max2=INT_MIN;
        for(int sz : cmpSize) {

            if(sz > max1) {

                max2 = max1;
                max1 = sz;
            }
            else if(sz > max2) {

                max2 = sz;
            }
        }

        return max1+max2+1;
    }
};