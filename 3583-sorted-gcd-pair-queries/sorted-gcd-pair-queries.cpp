class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = -1e9;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int>factors(maxi + 1, 0);
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 1; j * j <= num; j++){
                if(num % j == 0){
                    factors[j]++;
                if(num / j != j){
                    factors[num/j]++;
                }

                }

            }
        }

        vector<long long>pairsWithGcd(maxi + 1,0);
        for(int g = maxi; g >= 1; g--){
            long long count = factors[g];
            long long countPairs = count * (count - 1)/2;
            pairsWithGcd[g] = countPairs;


            for(int mul = 2 * g; mul <= maxi; mul += g){
                pairsWithGcd[g] -= pairsWithGcd[mul];
            }
        }
        vector<long long>prefixCountGcd(maxi + 1, 0);
        for(int g = 1; g <= maxi; g++){
            prefixCountGcd[g] = prefixCountGcd[g-1] + pairsWithGcd[g];
        }
        
        vector<int>result;
        for(long long idx : queries){
            int l = 1;
            int r = maxi;
            int temp = 1;
            while(l <= r){
                int mid = l + (r - l)/2;
                if(prefixCountGcd[mid] > idx){
                    temp = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            result.push_back(temp);
        }
return result;
        
        
    }
};