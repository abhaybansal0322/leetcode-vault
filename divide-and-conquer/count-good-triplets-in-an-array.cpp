class Solution {
    typedef long long ll;

    void updateSegment(int i, int l, int r, int updateIndex, vector<long long>& segmentTree)
    {
        if(l==r)
        {
            segmentTree[i]=1;
            return;
        }
        int mid = l + (r-l)/2;

        if(updateIndex <= mid)
        {
            updateSegment(2*i+1,l,mid,updateIndex,segmentTree);
        }
        else{
            updateSegment(2*i+2,mid+1,r,updateIndex,segmentTree);
        }

        segmentTree[i]= segmentTree[2*i+1]+segmentTree[2*i+2];
    }

    ll querySegment(int qs,int qe,int i,int l,int r,vector<long long>& segmentTree)
    {
        if(r < qs || l > qe)
            return 0;

        if(l >= qs && r <= qe)
            return segmentTree[i];

        int mid = l+(r-l)/2;
        
        ll left = querySegment(qs,qe,2*i+1,l,mid,segmentTree);
        ll right = querySegment(qs,qe,2*i+2,mid+1,r,segmentTree);

        return left+right;
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;++i)
        {
            mp[nums2[i]]=i;
        }

        vector<ll> segmentTree(4*n);
        ll result = 0;
        updateSegment(0,0,n-1,mp[nums1[0]],segmentTree);

        for(int i=1;i<n;++i)
        {
            int idx = mp[nums1[i]];
            ll leftComm = querySegment(0,idx,0,0,n-1,segmentTree);
            ll uncommon = i - leftComm;
            ll rightTotal = n-1-idx;
            ll rightComm = rightTotal - uncommon;

            result += leftComm*rightComm;

            updateSegment(0,0,n-1,idx,segmentTree);
        }
        
        return result;
    }
};