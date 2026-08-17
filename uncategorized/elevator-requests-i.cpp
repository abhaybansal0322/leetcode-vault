class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int t = 0;
        int curr = 0;

        for(auto& req : requests) {
            t += abs(curr-req);
            curr = req;
        }

        return t;
        
    }
};