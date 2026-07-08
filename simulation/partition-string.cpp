class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> vis;

        string toAdd;
        toAdd.push_back(s[0]);
        vis.insert(toAdd);
        vector<string> result;
        result.push_back(toAdd);
        string curr="";
        
        for(int i=1;i<s.length();i++) {
            curr.push_back(s[i]);
        
            if(vis.find(curr)==vis.end()) {

                result.push_back(curr);
                vis.insert(curr);
                curr = "";
            }
            
        }

        return result;
        
    }
};