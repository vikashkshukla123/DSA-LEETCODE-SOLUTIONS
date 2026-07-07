class Solution {
public:
long long solve(long long val){
    long long ans = 0;
    while(val != 0){
        ans += val % 10;
        val = val / 10;
    }

    return ans;
}
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '0'){
                ans += s[i];
            }
        }

        if(ans.empty()) return 0;

        long long val = stoll(ans);

        long long sum = solve(val);

        return (val * sum);



        
    }
};