class Solution {
    struct Node {
        int pref = 0;
        int suff = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };
    vector<Node> segTree;

    void build(int i, int l, int r, string& s) {

        if(l == r) {
            segTree[i] = {1,1,1,s[l],s[l]};
            return;
        }

        int mid = l+(r-l)/2;

        build(2*i+1,l,mid,s);
        build(2*i+2,mid+1,r,s);

        segTree[i] = Merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }

    void update(int i, int l, int r, int pos, char ch) {

        if(l == r) {
            segTree[i] = {1,1,1,ch,ch};
            return;
        }

        int mid = l+(r-l)/2;
        if(pos<=mid) {
            update(2*i+1,l,mid,pos,ch);
        } else {
            update(2*i+2,mid+1,r,pos,ch);
        }

        segTree[i] = Merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }

    Node Merge(Node& L, Node& R, int leftLen, int rightLen) {

        Node res;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pref = L.pref;
        if(L.pref == leftLen && L.rightChar == R.leftChar) {
            res.pref = L.pref + R.pref;
        }

        res.suff = R.suff;
        if(R.suff == rightLen && L.rightChar == R.leftChar) {
            res.suff = L.suff+R.suff;
        }

        res.maxLen = max(L.maxLen,R.maxLen);
        if(L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen,L.suff+R.pref);
        }

        return res;
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        segTree.assign(4*n,Node());
        build(0,0,n-1,s);

        int k = queryIndices.size();
        vector<int> result(k);

        for(int i=0;i<k;i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0,0,n-1,pos,ch);

            result[i] = (segTree[0].maxLen);
        }

        return result;
    }
};