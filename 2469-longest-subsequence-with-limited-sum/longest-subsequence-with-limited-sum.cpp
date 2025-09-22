class Solution {
public:
int calc(int a, vector<int>&nums){
    int n = nums.size();
    int maxi = -1e9;
    sort(nums.begin(),nums.end());
    int sum = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
        maxi = max(maxi,sum);
        if(maxi > a){
            break;
        }

        ans = i + 1;

        
    }
    return ans;
}
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;
        for(int i = 0; i<m; i++){
            int a = queries[i];
            int len = calc(a,nums);
            ans.push_back(len);

        }
        return ans;
    }
};