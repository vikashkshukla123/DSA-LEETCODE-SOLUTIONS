class Solution {
public:
int powCal(int a, int b){
    if(b == 0){
        return 1;
    }

    long long ans = powCal(a, b/2);
    long long result = ans * ans;

    if(b % 2 == 1){
        result *= a;
    }

    return result;
}
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n  == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        if(n == 3){
            return 4;
        }

        string s = bitset<20>(n).to_string();
        int m = s.length();
        int idx = 0;
        while(idx < 20 && s[idx] == '0'){
            idx++;
        }

        string original = s.substr(idx);
        int cnt = 0;
        int bit_index = 20 - idx - 1;
        int ans = powCal(2,bit_index + 1);

        return ans;
        

        
    }
};