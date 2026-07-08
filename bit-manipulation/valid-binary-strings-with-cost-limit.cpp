class Solution {
    vector<string> result;
    void helper(int n, int k, int currIdx, string curr, bool isPrev, int cost) {

        if((currIdx == n) && (cost <= k)) {
            result.push_back(curr);
            return;
        }
        if(cost > k) return;

        if(isPrev) {

            helper(n,k,currIdx+1,curr+"0",false,cost);
        } else {

            helper(n,k,currIdx+1,curr+"0",false,cost);
            helper(n,k,currIdx+1,curr+"1",true,cost+currIdx);
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        
        string curr = "";
        helper(n,k,0,curr,false,0);
        return result;
    }
};