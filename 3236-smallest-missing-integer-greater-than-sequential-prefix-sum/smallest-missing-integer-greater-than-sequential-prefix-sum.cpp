class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
            temp = temp + nums[i];
            }else{
                break;
            }
        }
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        while(true){
            if(st.find(temp) == st.end()){
                return temp;
                break;
            }else{
                temp ++;


            }
        
        }


    }
};