class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> result;
        for(auto& q : queries) {

            for(auto& d : dictionary) {

                int x = 0;
                for(int i=0;i<q.size();i++) {

                    if(q[i]!=d[i]) {
                        x++;
                    }

                    if(x > 2) break;
                }

                if(x <= 2) {

                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};