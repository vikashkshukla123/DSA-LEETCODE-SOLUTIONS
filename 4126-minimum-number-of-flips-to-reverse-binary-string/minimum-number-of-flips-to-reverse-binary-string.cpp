class Solution {
public:
    int minimumFlips(int n) {
        string binary = "";
        while(n != 0){
            int mod = n % 2;
            binary += to_string(mod);
            n = n / 2;
        }
        reverse(binary.begin(),binary.end());
        string newOriginal = "";
        int idx = 0;
        while(binary[idx] != '1'){
            idx++;
        }
        newOriginal = binary.substr(idx);


        int i = 0;
        int j = newOriginal.length() - 1;
        int ans = 0;
        while(i < j){
            if(newOriginal[i] != newOriginal[j]){
                ans += 2;
            }
            i++;
            j--;
        }
        return ans;
    }
};