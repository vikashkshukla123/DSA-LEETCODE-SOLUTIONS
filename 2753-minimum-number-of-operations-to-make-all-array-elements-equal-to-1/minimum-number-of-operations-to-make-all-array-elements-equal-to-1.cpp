class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                cnt1++;
            }
        }
        if(cnt1 > 0){
            return n - cnt1;
        }
        int operations = 1e9;

        for(int i = 0 ; i<n-1; i++){
            int GCD = nums[i];
            for(int j = i+1; j<n; j++){
                GCD =  gcd(GCD,nums[j]);
                if(GCD == 1){
                    operations = min(operations, j-i);
                    break;

                }
                

            }
        }
        if(operations == 1e9) return -1;
       
return operations + (n-1);

    }
};