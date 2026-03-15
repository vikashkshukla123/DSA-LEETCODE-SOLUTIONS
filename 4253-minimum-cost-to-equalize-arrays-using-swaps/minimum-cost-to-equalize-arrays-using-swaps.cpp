class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int>f1;
        unordered_map<int,int>f2;
        unordered_map<int,int>f3;

        for(int i = 0; i<n; i++){
            f1[nums1[i]]++;
            f3[nums1[i]]++;
        }

        for(int i = 0; i<m; i++){
            f2[nums2[i]]++;
            f3[nums2[i]]++;
        }
        int ans = -1;
        int cost_of_mismatch = 0;
        for(auto &[val,cnt] : f3){
            if(cnt % 2 == 1){
                return -1;
            }

            int to_be_in_each = cnt / 2;

            int mismatch = 0;

            if(f1.find(val) != f1.end()){
                mismatch = abs(to_be_in_each - f1[val]);
            }else{
                mismatch = abs(to_be_in_each - f2[val]);
            }

            cost_of_mismatch += mismatch;




        }

        return cost_of_mismatch / 2;
    }
};