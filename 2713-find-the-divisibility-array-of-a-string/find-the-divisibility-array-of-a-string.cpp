class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.length();
        long long value = 0;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int val = word[i] - '0';
            value = (value * 10 + val) % m;

            if(value % m == 0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }

        }

        return ans;
    }
};