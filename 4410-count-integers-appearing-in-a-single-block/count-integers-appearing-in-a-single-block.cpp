class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>lastidx;
        unordered_map<int,int>firstidx;
        unordered_map<int,int>freq;
        for(int i = n-1; i >= 0; i--){
            if(lastidx.find(nums[i]) == lastidx.end()){
                lastidx[nums[i]] = i;
            } 
            freq[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(firstidx.find(nums[i]) == firstidx.end()){
                firstidx[nums[i]] = i;
            }
        }

        unordered_set<int>visited;
        for(int i = 0; i < n; i++){
            int firstIdx = firstidx[nums[i]];
            int lastIdx = lastidx[nums[i]];

            if(lastIdx - firstIdx + 1 == freq[nums[i]]){
                visited.insert(nums[i]);
            }
            
            
        }

return visited.size();
       
    }
};