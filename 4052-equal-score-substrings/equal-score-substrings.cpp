class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();
        vector<int>prefix(n,0);
        for(int i = 0; i<n; i++){
            int val = s[i] - 'a' + 1;
            if(i == 0){
                prefix[i] = val;
            }else{
                prefix[i] = val + prefix[i-1];
            }
        }
        for(int i = 0; i<n-1; i++){
            int left = prefix[i] ;
            int right = prefix[n-1] - left;

            if(left == right){
                return true;
                break;
            }
        }
        return false;
    }
};