class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();
        int ops = INT_MAX;

        for(int i=0;i<n;i++) {
            int curr = i;
            string temp = s;
            rotate(temp.begin(),temp.begin()+i,temp.end());

            for(int r=0;r<n/2;r++) {
                int diff = abs(temp[r]-temp[n-r-1]);
                curr += min(diff,26-diff);
            }

            ops = min(curr,ops);
        }

        return ops;
    }
};