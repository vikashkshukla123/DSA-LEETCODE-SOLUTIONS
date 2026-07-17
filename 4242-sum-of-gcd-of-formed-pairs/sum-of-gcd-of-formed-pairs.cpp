class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n,0);
        vector<int>prefixGcd(n,0);

        maxi[0] = nums[0];
        prefixGcd[0] = gcd(nums[0], maxi[0]);

        for(int i = 1; i < n; i++){
            maxi[i] = max(nums[i], maxi[i-1]);
            prefixGcd[i] = gcd(nums[i], maxi[i]);
        }

        sort(prefixGcd.begin(),prefixGcd.end());
        vector<int>gcdPair;
        int i = 0;
        int j = n-1;
        while(i < j){
            int n1 = prefixGcd[i];
            int n2 = prefixGcd[j];

            int n3 = gcd(n1,n2);
            gcdPair.push_back(n3);

            i++;
            j--;
        }

        long long ans = 0;
        for(int i = 0; i < gcdPair.size(); i++){
            ans += (1LL * gcdPair[i]);
        }
return ans;
        
    }
};