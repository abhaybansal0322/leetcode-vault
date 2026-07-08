class Solution {
public:
    long long flowerGame(int n, int m) {
        
        long long numOfOddN = (n+1)/2;
        long long numOfEvenN = n - numOfOddN;
        long long numOfOddM = (m+1)/2;
        long long numOfEvenM = m - numOfOddM;

        return (numOfOddN*numOfEvenM)+(numOfOddM*numOfEvenN);
    }
};