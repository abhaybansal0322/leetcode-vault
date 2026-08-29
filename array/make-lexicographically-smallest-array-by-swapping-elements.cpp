class Solution {
    vector<int> parent;

    int find(int x) {
        if(parent[x] == x)  return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x,int y) {
        int px = find(x);
        int py = find(y);

        if(px != py) {
            parent[py] = px;
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        for(int i=0;i<n;i++)    parent[i] = i;

        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;
        
        sort(idx.begin(),idx.end(),[&] (int a,int b){
            return nums[a]<nums[b];
        });

        for(int i=1;i<n;i++) {
            int diff = abs(nums[idx[i]]-nums[idx[i-1]]);
            if(diff <= limit) unite(idx[i],idx[i-1]);
        }

        vector<int> res(n);
        unordered_map<int,vector<int>> grps;
        for(int i=0;i<n;i++)    grps[find(i)].push_back(i);

        for(auto& grp : grps) {

            vector<int> pos = grp.second;
            vector<int> vals;
            for(int p : pos)    vals.push_back(nums[p]);
            sort(vals.begin(),vals.end());

            for(int i=0;i<pos.size();i++)   res[pos[i]] = vals[i];
        }

        return res;
    }
};