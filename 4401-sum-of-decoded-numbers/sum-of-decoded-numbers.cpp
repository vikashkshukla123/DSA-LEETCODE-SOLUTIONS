class Solution {
public:
int mod = 1e9 + 7;
long long power(long long a, long long b){
    if(b == 0){
        return 1;
    }

    long long result1 = power(a,b/2) % mod;
    long long result = (result1 * result1) % mod;

    if(b % 2 == 1){
        result = (result * a) % mod;
    }

    return result;
}
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long a = nums[i] % 10;
            long long b = floor((double)nums[i] / 10);

            string str = to_string(b);
            string res1 = "";
            string res2 = "";
            res1 = str.substr(0, min((long long)str.length(), a));
            res2 = (a < (long long)str.length()) ? str.substr(a) : "";

            int k = 0;
            while(k < res1.length() && res1[k] == '0'){
                k++;  
            }

            int l = 0;
            while(l < res2.length() && res2[l] == '0'){
                l++;
            }


            string res3 = res1.substr(k, a - k);
            string res4 = res2.substr(l);

            if(res3.empty()){
                res3 = "0";
            }

            if(res4.empty()){
                res4 = "0";
            }


            long long c = stoll(res3);
            long long d = stoll(res4);

            long long product = power(c,d);

            ans = (ans + product) % mod;






            



        }

        return ans;
    }
};