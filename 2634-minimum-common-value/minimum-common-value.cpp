class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int>st;
        for(int i = 0; i<m; i++){
            st.insert(nums2[i]);
        }
        for(int i = 0; i<n; i++){
            int a = nums1[i];
            if(st.find(a) != st.end()){
                return a;
                break;
            }
        }
        return -1;
    }
};