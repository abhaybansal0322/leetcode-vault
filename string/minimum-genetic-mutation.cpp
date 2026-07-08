class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> bankset(bank.begin(),bank.end());
        unordered_set<string> vis;
        int level=0;

        queue<string> Q;
        Q.push(startGene);
        vis.insert(startGene);

        while(!Q.empty()) {

            int N = Q.size();
            
            while(N--) {

                string curr = Q.front(); Q.pop();

                if(curr==endGene) return level;

                for(char ch : "ACGT") {

                    for(int i=0;i<curr.length();i++) {

                        string neigh = curr;
                        neigh[i]=ch;

                        if(bankset.find(neigh)!=bankset.end() && vis.find(neigh)==vis.end()) {

                            Q.push(neigh);
                            vis.insert(neigh);

                        }
                            
                    }
                }
            }
            level++;
        }

        return -1;
    }
};