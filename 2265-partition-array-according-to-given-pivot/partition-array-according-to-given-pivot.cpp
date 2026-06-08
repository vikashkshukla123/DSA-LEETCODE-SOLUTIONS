class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>pivotLess;
        vector<int>pivotMore;
        vector<int>ans;

       int cntPivot = 0;
       for(int i = 0; i < n; i++){
           if(nums[i] == pivot){
            cntPivot++;
           }else if(nums[i] < pivot){
            pivotLess.push_back(nums[i]);
           }else{
            pivotMore.push_back(nums[i]);
           }
       }


       for(int i = 0; i < pivotLess.size(); i++){
        ans.push_back(pivotLess[i]);
       }

       while(cntPivot--){
        ans.push_back(pivot);
       }


       for(int i = 0; i < pivotMore.size(); i++){
        ans.push_back(pivotMore[i]);
       }



return ans;
    }
};