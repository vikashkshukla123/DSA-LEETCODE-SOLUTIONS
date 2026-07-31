class Solution {
public:
vector<int>ans;
int K;
long long t1[200001][4];
long long helper(int idx, int cnt, vector<int>&nums, vector<int>&subarray){
    int n = subarray.size();
    if(cnt == 0){
        return 0;
    }

    if(idx >= n){
        return LLONG_MIN;
    }
    if(t1[idx][cnt] != -1){
        return t1[idx][cnt];
    }

    long long take = subarray[idx] + helper(idx + K, cnt - 1, nums, subarray);
    long long  nottake = 0 + helper(idx + 1, cnt, nums, subarray);

    return t1[idx][cnt] =  max(take,nottake);
}
void solve(int idx, vector<int>&nums, int cnt,vector<int>&subarray){
    int n = nums.size();
    if(idx >= n) return;
    if(cnt == 0){
        return;
    }

    long long sumIfITakeIdxi = subarray[idx] + helper(idx + K, cnt - 1, nums, subarray);
    long long sumIfIDontTakeIdxi =  0 + helper(idx + 1, cnt, nums, subarray);

    if(sumIfITakeIdxi >= sumIfIDontTakeIdxi){
        ans.push_back(idx);

        solve(idx + K, nums, cnt - 1, subarray);

    }else{
        solve(idx + 1, nums, cnt , subarray);
    }

    
return;
    


}
vector<int> build(vector<int>&nums, int k){
    int n = nums.size();
    vector<int>ans;
    int left = 0;
    int right = 0;
    int sum = 0;
    while(right < n){
        sum += nums[right];
        while(left < n && right - left + 1 > k){
            sum -= nums[left];
            left++;
        }

        if(right - left + 1 == k){
            ans.push_back(sum);

        }
        right++;
    }

    return ans;
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        K = k;
        vector<int>subarray = build(nums, k);
        memset(t1,-1,sizeof(t1));
        solve(0,nums,3,subarray);
        return ans;
        
    }
};