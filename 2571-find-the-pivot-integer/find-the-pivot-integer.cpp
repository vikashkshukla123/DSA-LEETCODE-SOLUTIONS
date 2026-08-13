class Solution {
public:
    int pivotInteger(int n) {
        vector<int>prefixSum(n+1,0);
        prefixSum[1] = 1;
        for(int i = 1; i <= n; i++){
            prefixSum[i] = i + prefixSum[i-1];
        }

        int ans = -1;
        for(int i = 1; i <= n; i++){
            int sum1 = prefixSum[i];
            int sum2 = prefixSum[n] - prefixSum[i-1];
            if(sum1 == sum2){
                ans = i;
                break;
            }
        }

        return ans;
    }
};