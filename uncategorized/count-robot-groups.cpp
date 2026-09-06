class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        vector<int> sp;
        sp.reserve(n);

        for(int i=0;i<n;i++) {
            if(i>0 && (long long)position[i]-position[i-1] <= (long long)distance) {
                sp.back() = speed[i];
            } else {
                sp.push_back(speed[i]);
            }
        }

        int grps = 0;
        int frontSpeed = 0;

        for(int i=(int)sp.size()-1;i>=0;i--) {
            if(grps == 0 || sp[i]<=frontSpeed) {
                grps++;
                frontSpeed = sp[i];
            }
        }

        return grps;
    }
};