class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int XOR = 0;
        for(int i = 0; i<n; i++){
            XOR ^= nums[i];
            st.insert(nums[i]);
        }
        if(XOR != 0) return n;
        else if (XOR == 0 && st.size() == 1 && *st.begin() == 0){
            return 0;
        }else{
            return n-1;
        }
        return n;

    }
 };