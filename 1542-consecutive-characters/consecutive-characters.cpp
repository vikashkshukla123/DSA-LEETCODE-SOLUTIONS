class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int maxi = 1;
        int len = 1;
        for(int i = 0; i<n-1;){
            char ch = s[i];
            int j = i+1;
            while(j < n && s[j] == ch){
                len++;
                j++;
            }
            maxi = max(maxi,len);
            len = 1;
            i = j;
        }
return maxi;
        
    }
};