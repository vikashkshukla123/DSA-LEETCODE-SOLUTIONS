class Solution {
public:
int find(vector<int>&nums, int k, int x, int y){
    int n = nums.size();
    int op = 0;
    for(int i = 0; i < n; i++){
        int target = -1;
        if(i % 2 == 0){
            target = x;
        }else{
            target = y;
        }

        if(nums[i] % k == target){
            continue;
        }

        int diff = abs(nums[i] % k - target);
        op += min(diff, k - diff);

    }   
    return op; 
}
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int min_op = 1e9;
        for(int x = 0; x < k; x++){
            for(int y = 0; y < k; y++){
                if(x == y) continue;
                int operation = find(nums,k,x,y);
                min_op = min(min_op, operation);
            }
        }
        return min_op;
    }
};