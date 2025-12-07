class Solution {
public:
int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int evenCount = 1;
        int oddCount = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                evenCount++;
                ans += oddCount;
                ans = ans % mod;
                
            }else{
                oddCount++;
                ans += evenCount;
                ans = ans % mod; 
            }


        }
        
        return ans;
    }
};