class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;
        unordered_set<int>st;
        bool allEven = false;
        while(true){
            st.clear();
            if(!allEven){
                for(int i = 0; i<n; i++){
                    if(nums[i] % 2 == 0){
                        st.insert(nums[i]);
                    }else{
                        nums[i] = nums[i] - 1;
                        st.insert(nums[i]);
                        operation++;
                    }
                }
                allEven = true;

            }else{
                operation++;
                for(int i = 0; i<n; i++){
                    nums[i] = nums[i] / 2;
                    st.insert(nums[i]);

                    if(nums[i] % 2 == 1){
                        allEven = false;
                    }
                }
            }
            if(st.size() == 1 && *st.begin() == 0){
                break;
            }

        }
        return operation;
    }
};