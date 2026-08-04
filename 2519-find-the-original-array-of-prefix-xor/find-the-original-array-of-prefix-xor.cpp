class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n,0);
        ans[0] = pref[0];

        int curr_xor = pref[0];
        for(int i = 1; i < n; i++){
             int value_to_get = pref[i];
             int result = 0;

             for(int bit = 0; bit < 20; bit++){
                int value_to_get_bit = ((1 << bit) & value_to_get);
                int curr_xor_bit = ((1  <<  bit) & curr_xor);

                if((value_to_get_bit != 0 && curr_xor_bit == 0) || (value_to_get_bit == 0 && curr_xor_bit != 0)){
                    result = result | (1 << bit);

                }
             }
             ans[i] = result;
             curr_xor ^= result;
        }


        return ans;
    }
};