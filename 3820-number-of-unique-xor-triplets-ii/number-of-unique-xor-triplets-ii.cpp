class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        unordered_set<int>uniqueXor;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                uniqueXor.insert(nums[i] xor nums[j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(auto it = uniqueXor.begin(); it != uniqueXor.end(); it++){
                int val = *it;
                st.insert(val ^ nums[i]);
            }
        }
       

       return st.size();
        
    }
};