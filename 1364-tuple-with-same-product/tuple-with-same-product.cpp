class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,long long>mp;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                long long mul = nums[i] * nums[j];
                mp[mul]++;
            }
        }

        int ans = 0;
        for(auto &[val,cnt] : mp){
            if(cnt == 1){
                continue;
            }else{
                int total_num = cnt * 2;
                int combination = total_num * 1;
                int num_left = total_num - 2;
                combination *= num_left * 1;


                ans += combination;
            }
        }
        return ans;
    }
};