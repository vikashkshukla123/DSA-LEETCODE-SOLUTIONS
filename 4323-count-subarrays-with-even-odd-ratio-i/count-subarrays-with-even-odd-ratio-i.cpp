class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int>countOdd(n,0);
        vector<int>countEven(n,0);
        if(nums[0] % 2 == 1){
            countOdd[0] += 1;
        }else{
            countEven[0] += 1;
        }

        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == 1){
                countOdd[i] = 1 + countOdd[i-1];
                countEven[i] = countEven[i-1];
            }else{
                countEven[i] = 1 + countEven[i-1];
                countOdd[i] = countOdd[i-1];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int y = countOdd[j] - (i-1 >= 0 ? countOdd[i-1] : 0);
                int x = countEven[j] - (i-1 >= 0 ? countEven[i-1] : 0);
                if(y <= 0) continue;

                if(1LL * x * b <= 1LL * a *y){
                    ans++;
                }

                
            }
        }
        return ans;
    }
};