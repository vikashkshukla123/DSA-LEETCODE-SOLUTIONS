class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi  = -1e9;
        int idx = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                idx = i;
            }

        }
        long long ascending_sum = 0;
        long long descending_sum = 0;
        for(int i = 0; i<=idx; i++){
            ascending_sum += nums[i];
        }
        

        for(int i = idx; i < n; i++){
            descending_sum += nums[i];
        }


        if(ascending_sum > descending_sum) return 0;
        else if(descending_sum > ascending_sum) return 1;
        return -1;
        
    }
};