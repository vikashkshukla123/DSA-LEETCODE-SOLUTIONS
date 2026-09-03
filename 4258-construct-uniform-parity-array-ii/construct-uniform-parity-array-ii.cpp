class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        bool allOdd = true;
        if(nums1[0] % 2 == 0){
            allOdd = false;
        }
        if(allOdd){
            for(int i = 1; i < n; i++){
                if(nums1[i] % 2 == 1){
                    continue;
                }
                if((nums1[i] - nums1[0]) % 2 == 0){
                    allOdd = false;
                }
                
            }
        }

        bool allEven = true;
        if(nums1[0] % 2 == 1){
            allEven = false;
        }

        if(allEven){
            for(int i = 1; i < n; i++){
                if(nums1[i] % 2 == 0){
                    continue;
                }
                if((nums1[i] - nums1[0]) % 2 == 1){
                    allEven = false;
                } 
            }

        }

if(allOdd || allEven){
    return true;
}

return false;

    }
};