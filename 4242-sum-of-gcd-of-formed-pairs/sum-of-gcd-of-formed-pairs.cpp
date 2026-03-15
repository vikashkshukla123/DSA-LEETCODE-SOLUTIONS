class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>gcdVal(n,0);
        vector<int>maxi(n,0);
        maxi[0] = nums[0];
        for(int i = 1; i<n; i++){
            maxi[i] = max(nums[i], maxi[i-1]);
        }

        for(int i = 0; i<n; i++){
            long long val = gcd(nums[i],maxi[i]);
            gcdVal[i] = val;
        }

        sort(gcdVal.begin(),gcdVal.end());
        int m = gcdVal.size();


        long long total_sum = 0;
        int i = 0;
        int j = n-1;
        while(i < j){
            int val1 = gcdVal[i];
            int val2 = gcdVal[j];

            long long val = gcd(val1,val2);
            total_sum += val;
            i++;
            j--;
        }

        return total_sum;

        
    }
};