class Solution {
    int helper(string time) {

        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));
        int s = stoi(time.substr(6,2));

        return h*60*60 + m*60 + s;
    }
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        
        return helper(endTime) - helper(startTime);
    }
};