class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit = 0; bit < 32; bit++){
            int cntZero = 0;
            int cntOne = 0;
            for(int i = 0; i < n; i++){
                if(((1 << bit) & nums[i]) != 0){
                    cntOne++;
                }else{
                    cntZero++;
                }

            }

            int need = -1;
            if(cntOne % 3 == 0){
                need = 0;
            }else{
                need = 1;
            }

            if(((1 << bit) & ans) == 0 && need == 0){
                continue;
            }

            ans = (ans | (1 << bit));
        }
     return ans;   
    }
};