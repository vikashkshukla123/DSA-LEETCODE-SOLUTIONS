class Solution {
public:
int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = queries.size();
        for(int i = 0; i<n; i++){
            int idx  = queries[i][0];
            int right = queries[i][1];
            long long k = queries[i][2];
            long long val = queries[i][3];


            while(idx <= right){
                long long num = nums[idx];
                num  = (num * val) % mod;
                nums[idx] = num;
                idx += k;
            }
        }
        
        int XOR = 0;
        for(int i = 0; i<nums.size(); i++){
            XOR ^= nums[i];
        }

        return XOR;
    }
};