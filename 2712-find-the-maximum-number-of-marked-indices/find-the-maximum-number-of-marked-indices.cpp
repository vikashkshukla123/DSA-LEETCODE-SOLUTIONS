class Solution {
public:
bool isPossible(int mid, vector<int>&nums){
    int n = nums.size();
    int i = 0;
    int j = nums.size() / 2;
    int j_abs = j;
    int cnt = 0;

    while(i < n && i < j_abs && j < n){
        if(nums[i] * 2 <= nums[j]){
            cnt += 2;
            i++;
            j++;
        }else{
            j++;
        }
    }

    return (cnt >= mid);
    
}
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = n;

        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, nums)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};