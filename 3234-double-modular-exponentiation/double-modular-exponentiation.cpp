class Solution {
public:
long long calpow(long long a, long long b, long long mod){
    if(b == 0){
        return 1;
    }
    long long result1 = calpow(a,b/2,mod) % mod;
    long long result = (result1 * result1) % mod;

    if(b % 2 == 1){
        result = (result * (a % mod)) % mod;
    }

    return result;
}
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n = variables.size();
        vector<int>ans;
        for(int i = 0; i < variables.size(); i++){
            long long ai = 1LL* variables[i][0];
            long long bi = 1LL* variables[i][1];
            long long ci = 1LL*variables[i][2];
            long long mi = 1LL*variables[i][3];

            long long powa = calpow(ai,bi,10);
            long long powb = calpow(powa,ci,mi);

            if(powb == 1LL * target){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};