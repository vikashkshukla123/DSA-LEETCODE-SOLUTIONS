class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int operations = 0;
        unordered_set<int>st;
        while(st.size() != k){
            int element = nums[n-1];
            if(element <= k){
                st.insert(element);
            }
            operations++;
            n--;
            

        }
        return operations;
    }
};