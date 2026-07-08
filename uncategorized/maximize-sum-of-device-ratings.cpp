class Solution {

    pair<long long, long long> getValue(const vector<int>& device) {
    long long smallest = LLONG_MAX;
    long long secondSmallest = LLONG_MAX;

    for (int capacity : device) {
        if (capacity < smallest) {
            // Previous smallest becomes the second smallest
            secondSmallest = smallest;
            smallest = capacity;
        } 
        else if (capacity < secondSmallest) {
            // This also handles duplicate values correctly
            secondSmallest = capacity;
        }
    }

        // first  = second smallest
        // second = smallest
        return {secondSmallest, smallest};
    }
public:
    long long maxRatings(vector<vector<int>>& units) {
        
        int m = units.size();
        int n = units[0].size();

        if(n == 1) {

            long long answer = 0;
            for(auto device : units) {

                answer += device[0];
            }

            return answer;
        }

        long long globalMin = INT_MAX;
        long long sacrifice = INT_MAX;
        long long result = 0;

        for(auto device : units) {
            
            auto [secondSmallest,smallest] = getValue(device);

            sacrifice = min(secondSmallest,sacrifice);
            globalMin = min(globalMin,smallest);
            result += secondSmallest;
        }

        return result - sacrifice + globalMin;


    }
};