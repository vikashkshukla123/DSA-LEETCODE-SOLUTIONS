class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums.insert(nums.begin(),1,0);
        long long sum = 0;
        for(int i = 1; i < nums.size() && k != 0; i++){
            int val1 = nums[i];
            int val2 = nums[i-1];

            if(val1 - val2 <= 1){
                continue;
            }

            int diff = val1 - val2 - 1;

            if(k <= diff){
                long long start = val2 + 1;
                while(k--){
                    sum += start;
                    start++;
                }

                break;
            }else{
                long long sum_upto_val1 = 1LL * val1 * (val1 + 1) / 2;
                long long sum_upto_val2 = 1LL * val2 * (val2 + 1) / 2;

                k -= diff;
                sum += (sum_upto_val1 - sum_upto_val2 - val1);



            }

            
        }

        if(k > 0){
            long long start = nums[nums.size() - 1] + 1;
            while(k--){
                sum += start;
                start++;
            }
        }

        
return sum;

    }
};