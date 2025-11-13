class Solution {
public:
    int minChanges(int n, int k) {
        string s1 = bitset<32>(n).to_string();
        string s2 = bitset<32>(k).to_string();

        int i = 0;
        int j = 0;
        int l = s1.length();
        int m = s2.length();
        int ans = 0;
        while(i < l && j < m){
            if(s1[i] == '1' && s2[j] == '0'){
                ans++;
            }
            else if(s1[i] == '0' && s2[j] == '1'){
                return -1;
            }
            i++;
            j++;
        }
        return ans;



        
    }
};