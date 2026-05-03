class Solution {
public:
void calculatePrime(vector<int>&primes){
    primes[0] = 0;
    primes[1] = 0;

    for(int i = 2 ; i * i < primes.size(); i++){
        if(primes[i] == 1){
            for(int j = i * i; j < primes.size(); j += i){
                primes[j] = 0;
            }
        }
    }


return;

}
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int m = stoi(s);

        int range_min = min(n,m);
        int range_max = max(n,m);
        
        vector<int>primes(range_max + 1, 1);
        calculatePrime(primes);

        int sum = 0;
        for(int range = range_min; range <= range_max; range++){
            if(primes[range] == 1){
                sum += range;
            }
        }
        return sum;
    }
};