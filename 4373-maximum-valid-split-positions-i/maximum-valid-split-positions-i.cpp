class Solution {
public:
int solve(vector<int>&array){
    int n = array.size();
    vector<int>prefixGCD(n,0);
    vector<int>suffixGCD(n,0);
    prefixGCD[0] = array[0];
    suffixGCD[n-1] = array[n-1];
    for(int i = 1; i < n; i++){
        prefixGCD[i] = gcd(prefixGCD[i-1],array[i]);
    }
    for(int i = n-2; i >= 0; i--){
        suffixGCD[i] = gcd(array[i],suffixGCD[i+1]);
    }

    int ans = 0;
    for(int idx = 0; idx < n-1; idx++){
        int val1 = prefixGCD[idx];
        int val2 = suffixGCD[idx + 1];

        if(val1 == val2){
            ans++;
        }
    }

    return ans;
}
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<int>prefixGCD(n,0);
        vector<int>suffixGCD(n,0);
        prefixGCD[0] = nums[0];
        suffixGCD[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
        prefixGCD[i] = gcd(prefixGCD[i-1],nums[i]);
        }
        for(int i = n-2; i >= 0; i--){
        suffixGCD[i] = gcd(nums[i],suffixGCD[i+1]);
         }

        for(int idx = 0; idx < n-1; idx++){
        int val1 = prefixGCD[idx];
        int val2 = suffixGCD[idx + 1];

        if(val1 == val2){
            result++;
        }
    }

        for(int remove = 0; remove < n; remove++){
            vector<int>array;
            for(int i = 0; i < n; i++){
                if(i == remove){
                    continue;
                }
                array.push_back(nums[i]);
                
            }
            int ans = solve(array);
            result = max(result,ans);
        }
        return result;

    }
};