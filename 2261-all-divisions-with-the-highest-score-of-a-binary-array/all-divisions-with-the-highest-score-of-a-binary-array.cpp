class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int>num0(n+2);
        vector<int>num1(n+2);

        num0[0] = 0;
        num1[0] = 0;
        int cnt1 = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                num0[i+1] = 1 + num0[i]; 
            }else{
                num0[i+1] = num0[i];
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                num1[i+1] = 1 + num1[i]; 
                cnt1++;
            }else{
                num1[i+1] = num1[i];
            }
        }

        int maxi = -1e9;
        vector<int>ans1(n+1);
        unordered_map<int,int>mp;
        for(int i = 0; i<=n; i++){
            int zeros = num0[i];
            int ones = cnt1 - num1[i];

            if(ones + zeros > maxi){
                maxi = ones + zeros;
                
            }
            ans1[i] = ones + zeros;;
            

        }
        vector<int>ans;
        for(int i = 0; i<=n; i++){
            if(ans1[i] == maxi){
                ans.push_back(i);
            }
        }
        return ans;

        
    }
};