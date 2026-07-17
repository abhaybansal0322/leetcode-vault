class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        
        int maxElement = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxElement+1,0);

        for(auto& num : nums) freq[num]++;

        vector<long long> exactPairs(maxElement+1,0);

        for(int g=maxElement;g>=1;g--) {

            long long divCount = 0;
            for(int mul=g;mul<=maxElement;mul+=g) divCount += freq[mul];

            long long totalPairs = divCount * (divCount-1)/2;

            for(int mul=2*g;mul<=maxElement;mul+=g) {
                totalPairs -= exactPairs[mul];
            }
            exactPairs[g] = totalPairs;
        }

        vector<long long> prefix(maxElement + 1, 0);

        for (int g = 1; g <= maxElement; g++) {
            prefix[g] = prefix[g - 1] + exactPairs[g];
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (long long query : queries) {
            int gcdValue =
                upper_bound(prefix.begin() + 1, prefix.end(), query)
                - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};