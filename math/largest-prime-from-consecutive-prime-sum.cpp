class Solution {

    vector<bool> isPrime;

    vector<int> seive(int n) {

        isPrime.assign(n+1,true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2;i*i<=n;i++) {

            if(isPrime[i]) {

                for(int j=i*i;j<=n;j+=i) {

                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i=2;i<=n;i++) {

            if(isPrime[i])  primes.push_back(i);
        }

        return primes;
    }
public:
    int largestPrime(int n) {
        
        int sum = 0,best=0;
        vector<int> primes = seive(n);
        for(auto x : primes) {

            if(sum + x > n) break;
            sum += x;

            if(isPrime[sum])    best = sum;
        }

        return best;
    }
};