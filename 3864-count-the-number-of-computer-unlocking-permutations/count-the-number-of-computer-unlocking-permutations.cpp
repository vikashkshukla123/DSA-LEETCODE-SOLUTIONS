class Solution {
public:
    static const int mod = 1e9 + 7;

    long long fac(int a) {
        long long ans = 1;
        for (int i = 2; i <= a; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i = 1; i<n; i++){
            if(complexity[i] < complexity[0]){
                return 0;
            }
        }

        sort(complexity.begin(),complexity.end());
        if (n >= 2 && complexity[0] >= complexity[1]) {
            return 0;
        }

        return fac(n - 1);
    }
};
