class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        long long product_without_zero = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                product_without_zero *= nums[i];
            }
        }


        vector<int>ans;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(num == 0){
                if(cnt > 1){
                    ans.push_back(0);
                }else{
                    ans.push_back(product_without_zero);
                }
            }else{
                if(cnt > 0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(product_without_zero / nums[i]);
                }
            }

        }
        return ans;
    }
};