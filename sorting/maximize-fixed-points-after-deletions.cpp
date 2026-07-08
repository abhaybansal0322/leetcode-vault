class Solution {
    struct segTree {
        int n;
        vector<int> seg;

        segTree(int n) : n(n), seg(4*n,0) {}

        void update(int idx,int val,int node,int l,int r) {
            if(l == r) {
                seg[node] = max(seg[node],val);
                return;
            }
            int mid = (l+r)/2;
            if(idx <= mid) update(idx,val,2*node,l,mid);
            else update(idx,val,2*node+1,mid+1,r);

            seg[node] = max(seg[2*node],seg[2*node+1]);
        }

        int query(int ql,int qr,int node,int l,int r) {
            if(qr<l || ql>r) return 0;
            if(ql<=l && qr>=r) return seg[node];

            int mid = (l+r)/2;

            return max(query(ql,qr,2*node,l,mid),query(ql,qr,2*node+1,mid+1,r));
        }
    };
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> points;

        for(int i=0;i<n;i++) {
            int d = i-nums[i];
            if(d>=0) points.push_back({nums[i],d});
        }

        if(points.empty()) return 0;
        vector<int> ds;
        for(auto &p : points) ds.push_back(p.second);
        sort(ds.begin(),ds.end());
        ds.erase(unique(ds.begin(),ds.end()),ds.end());

        auto getId = [&](int d) {
          return int(lower_bound(ds.begin(),ds.end(),d)-ds.begin());  
        };

        sort(points.begin(),points.end());

        segTree st(ds.size());
        int ans = 0;

        for(int i=0;i<points.size();) {
            int j=i;
            vector<pair<int,int>> pending;

            while(j < (int)points.size() && points[j].first == points[i].first) {
                int d = points[j].second;
                int id = getId(d);
                int best = st.query(0,id,1,0,st.n-1);
                int dp = best+1;
                pending.push_back({id,dp});
                ans = max(ans,dp);
                j++;
            }

            for(auto& x : pending) {
                st.update(x.first,x.second,1,0,st.n-1);
            }
            i = j;
        }
        return ans;
    }
};