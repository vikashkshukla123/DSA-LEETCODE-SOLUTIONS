class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        if(k == 0){
        while(i < n && j < n){
            if(nums1[i] != nums2[j]){
                return -1;
                
            }
            i++;
            j++;
        }
        return 0;

        }

        long long cnt = 0;
        long long increase = 0;
        long long decrease = 0;

        for(int i = 0; i < n; i++){

            if(abs(nums1[i] - nums2[i]) % k != 0){
                return -1;
            }

            if(nums1[i] == nums2[i]){
                continue;
            }


            else if(nums1[i] < nums2[i]){
                int operations = (nums2[i] - nums1[i])/ k;
                increase += operations;
            }else{
                int operations = (nums1[i] - nums2[i])/k;
                decrease += operations;
            }



        }
  



        if(increase != decrease){
            return -1;
        }

        return (increase + decrease)/2;;



        
    }
};