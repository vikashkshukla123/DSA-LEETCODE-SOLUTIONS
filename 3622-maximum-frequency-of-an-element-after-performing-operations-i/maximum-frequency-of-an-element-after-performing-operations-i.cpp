class Solution {
public:
int getIndex(vector<int>&nums, int target){
    int l = 0;
    int r = nums.size();

    while(l < r){
        int mid = (l+r)/2;

        if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
int maximumFreq(int target, vector<int>&nums, unordered_map<int,int>&freq, int k, int numOperations){
    int left = getIndex(nums, target - k);
    int right = getIndex(nums, target + k + 1);


    int operations = right - left - freq[target];


    return min(operations, numOperations) + freq[target];



}

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        unordered_map<int,int>freq;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
            st.insert(nums[i]-k);
            st.insert(nums[i]+k);
            st.insert(nums[i]);
        }
        int maxNum = nums[n-1];
        int ans = 0;

        for(int target : st){
            ans = max(ans, maximumFreq(target, nums, freq, k, numOperations));

        }
return ans;
        
    }
};