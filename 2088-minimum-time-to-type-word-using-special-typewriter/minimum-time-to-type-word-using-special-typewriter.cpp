class Solution {
public:

    int minTimeToType(string word) {
        int n = word.length();
        char curr = 'a';
        int ans = 0;
        for(int i = 0; i<n; i++){
            char ch = word[i];
            int idx = abs(curr - ch);
            int idx_anti = abs(26 - idx);

            if(idx < idx_anti){
                ans += 1 + idx;
            }else if(idx > idx_anti){
                ans += 1 + idx_anti;
            }else{
                ans += 1 + idx;
            }
            curr = word[i];

        }
        return ans;
        
    }
};