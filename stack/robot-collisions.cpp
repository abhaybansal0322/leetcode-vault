class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<vector<int>> robots;

    
    for (int i = 0; i < n; ++i) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    sort(robots.begin(), robots.end());

    vector<vector<int>> output;

    for (int i = 0; i < robots.size(); ++i) {
        
        while (!output.empty() && output.back()[2] == 'R' && robots[i][2] == 'L') {
            if (robots[i][1] > output.back()[1]) {
                
                robots[i][1]--;
                output.pop_back();
            } else if (robots[i][1] < output.back()[1]) {
                
                output.back()[1]--;
                robots[i][1] = 0;
                break;
            } else {
                
                output.pop_back();
                robots[i][1] = 0;
                break;
            }
        }
        if (robots[i][1] > 0) {
            output.push_back(robots[i]);
        }
    }

    
    vector<int> ans;
    sort(output.begin(), output.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[3] < b[3];
    });
    
    for (const auto& robot : output) {
        ans.push_back(robot[1]);
    }
    
    return ans;
}

};