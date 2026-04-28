class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int>st;
        int n = nums1.size();
        int m = nums2.size();
        int k = nums3.size();
        unordered_set<int>st1;
        unordered_set<int>st2;
        unordered_set<int>st3;
        for(int i = 0; i<n; i++){
            st.insert(nums1[i]);
            st1.insert(nums1[i]);
        } 
        for(int i = 0; i<m; i++){
            st.insert(nums2[i]);
            st2.insert(nums2[i]);
        } 
        for(int i = 0; i<k; i++){
            st.insert(nums3[i]);
            st3.insert(nums3[i]);
        } 

        vector<int>ans;
        for(auto it = st.begin(); it != st.end(); it++){
            int val = *it;
            if(st1.count(val) && st2.count(val) || st2.count(val) && st3.count(val) || st3.count(val) && st1.count(val)){
                ans.push_back(val);
            }
        }
        return ans;
    }
};