class segTree {

    vector<int> maxV,minV;
    int n;

    public:

    segTree(vector<int>& nums) {

        n = nums.size();
        maxV.resize(4*n);
        minV.resize(4*n);
        build(0,0,n-1,nums);
    }

    void build(int idx, int l, int r, vector<int>& nums) {

        if(l == r) {

            maxV[idx] = minV[idx] = nums[l];
            return;
        }

        int mid = l+(r-l)/2;
        build(2*idx+1,l,mid,nums);
        build(2*idx+2,mid+1,r,nums);

        maxV[idx] = max(maxV[2*idx+1],maxV[2*idx+2]);
        minV[idx] = min(minV[2*idx+1],minV[2*idx+2]);  
    }

    int queryMax(int idx,int l,int r,int ql,int qr) {

        if(l>=ql && r<=qr) return maxV[idx];
        if(ql > r || qr < l)    return INT_MIN;

        int mid = l+(r-l)/2;
        
        return max(

            queryMax(2*idx+1,l,mid,ql,qr), queryMax(2*idx+2,mid+1,r,ql,qr)
        );
    }

    int queryMin(int idx,int l,int r,int ql,int qr) {

        if(l>=ql && r<=qr) return minV[idx];
        if(ql > r || qr < l)    return INT_MAX;

        int mid = l+(r-l)/2;
        
        return min(

            queryMin(2*idx+1,l,mid,ql,qr), queryMin(2*idx+2,mid+1,r,ql,qr)
        );
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        segTree st(nums);
        int n = nums.size();
        priority_queue<pair<int,pair<int,int>>> pq;

        long long res = 0;

        for(int l = 0;l<n;l++) {
            int r = n-1;
            int diff = st.queryMax(0,0,n-1,l,r)-st.queryMin(0,0,n-1,l,r);
            pq.push({diff,{l,r}});
        }

        while(k--) {
            
            auto[val, lr] = pq.top();  pq.pop();
            auto[l,r] = lr;

            res += val;
            r--;
            if(l<=r) {

                int diff = st.queryMax(0,0,n-1,l,r)-st.queryMin(0,0,n-1,l,r);
                pq.push({diff,{l,r}});
            }
        }

        return res;
    }
};