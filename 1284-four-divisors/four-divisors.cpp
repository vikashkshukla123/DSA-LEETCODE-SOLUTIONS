class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int num = nums[i];
            int cnt = 0;
            int div_sum = 0;

            for(int i = 1; i*i<=num; i++){
                if(num % i == 0){
                    cnt++;
                    div_sum += i;



                    if(num / i != i){
                        cnt++;
                        div_sum += num/i;
                    }

                    if(cnt > 4){
                        break;
                    }

                }

                
            }
            if(cnt == 4){
                ans += div_sum;
            }

        
        }
        return ans;
    }
};