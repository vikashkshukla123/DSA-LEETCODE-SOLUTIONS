class Solution {
public:
    vector<int> decimalRepresentation(int n) {
       string s = to_string(n);
       int k = s.length();
       vector<int>ans;
       int j = 0;
       for(int i = k - 1; i >= 0; i--){
        int value = s[i] - '0';
        if(value != 0){
            ans.push_back(value * pow(10,j));
        }
        j++;


       }
       reverse(ans.begin(),ans.end());
       return ans;
        
    }
};