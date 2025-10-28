class Solution {
public:
bool isValid(vector<int>nums, int curr , int dir){
    int n =  nums.size();
    while(curr >= 0 && curr < n){
        if(nums[curr] == 0){
            curr = curr + dir;
        }else{
            nums[curr]--;
            if(dir == -1){
                dir = 1;
            }else{
                dir = -1;
            }
            curr = curr + dir;
        }
    }

    bool flag = true;
    for(int num : nums){
        if(num != 0){
            flag = false;
            break;
        }
    }
    return flag;
}
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0) {
                continue;
            }
            cnt += isValid(nums, i,-1);
            cnt += isValid(nums,i,1);
            
        }
        
        return cnt;
    }
};