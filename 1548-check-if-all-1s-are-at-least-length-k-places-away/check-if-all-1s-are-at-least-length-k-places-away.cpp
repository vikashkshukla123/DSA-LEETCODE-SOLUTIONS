class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>a;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                a.push_back(i);

            }
        }
        if(a.size() == n && k == 0) return true;

        int m  = a.size();
        for(int i = 0; i<m-1;  i++){
            for(int j = i+1; j<m; j++){
                if(a[j] - a[i] - 1 < k){
                    return false;
                }
            }
        }
        return true;
    }
};