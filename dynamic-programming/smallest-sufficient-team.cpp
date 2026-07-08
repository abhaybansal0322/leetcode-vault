class Solution {
public:
    int n, m;
    vector<int> personMask;
    vector<vector<int>> dp;
    vector<int> allSkillsTeam; 
    
    vector<int> solve(int mask) {
        if (mask == (1 << n) - 1) return {}; // all skills covered
        if (!dp[mask].empty()) return dp[mask]; 
        
        vector<int> bestTeam; 
        for (int i = 0; i < m; i++) {
            int newMask = mask | personMask[i];
            if (newMask == mask) continue; // person adds no new skills
            
            vector<int> team = solve(newMask);
            team.push_back(i);
            
            if (bestTeam.empty() || team.size() < bestTeam.size()) {
                bestTeam = team;
            }
        }
        return dp[mask] = bestTeam;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size();
        m = people.size();
        
        unordered_map<string,int> skillId;
        for (int i = 0; i < n; i++) skillId[req_skills[i]] = i;
        
        personMask.assign(m, 0);
        for (int i = 0; i < m; i++) {
            for (auto& skill : people[i]) {
                if (skillId.count(skill)) {
                    personMask[i] |= (1 << skillId[skill]);
                }
            }
        }
        
        dp.assign(1 << n, {});
        return solve(0);
    }
};
