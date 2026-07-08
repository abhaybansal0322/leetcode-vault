class Solution {
    unordered_map<int,vector<int>> rowWise;
    unordered_map<int,vector<int>> colWise;
    
    bool isCovered(int i,int j)
    {
        //CheckUpper
        auto it = lower_bound(colWise[j].begin(),colWise[j].end(),i);
        if(it == colWise[j].begin())
            return false;
        //CheckLower
        it = upper_bound(colWise[j].begin(),colWise[j].end(),i);
        if(it == colWise[j].end())
            return false;
        //CheckLeft
        it = lower_bound(rowWise[i].begin(),rowWise[i].end(),j);
        if(it == rowWise[i].begin())
            return false;
        //CheckRight
        it = upper_bound(rowWise[i].begin(),rowWise[i].end(),j);
        if(it == rowWise[i].end())
            return false;
        
        
        return true;
    }
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // int n = buildings.size();
        
        for(auto &b : buildings)
            {
                int i = b[0];
                int j = b[1];
                rowWise[i].push_back(j);
                colWise[j].push_back(i);
            }
        

        for (auto& [i, vec] : rowWise)
            sort(vec.begin(), vec.end());
        for (auto& [j, vec] : colWise)
            sort(vec.begin(), vec.end());

        int res = 0;

        for(auto &b : buildings)
            {
                int i = b[0];
                int j = b[1];
                if(isCovered(i,j))
                    res++;
            }

        return res;   
    }
};