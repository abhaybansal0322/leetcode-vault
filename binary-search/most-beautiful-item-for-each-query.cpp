class Solution {
public:

    int findIndex(vector<vector<int>>& items,int l,int r,int num)
    {
        int index = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(items[mid][0] <= num)
            {
                index = mid;
                l=mid+1;
            }
            else{
                r = mid - 1;
            }
        }

        return index;
        
    }


    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();

        sort(items.begin(),items.end());

        vector<int> Max(n);
        vector<int> result;

        int val = INT_MIN;

        for(int i=0;i<n;i++)
        {
            val = max(val,items[i][1]);
            Max[i] = val;
        }

        for(int i=0;i<m;i++)
        {
            int index = findIndex(items,0,n-1,queries[i]);
            if(index == -1)
            {
                result.push_back(0);
            }
            else{
                result.push_back(Max[index]);
            }
        }

        return result;
        
    }
};