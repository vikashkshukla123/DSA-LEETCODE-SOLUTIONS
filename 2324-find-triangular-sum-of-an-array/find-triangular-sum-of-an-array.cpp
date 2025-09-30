// class Solution {
// public:
//     int triangularSum(vector<int>& nums) {
//         while(nums.size() > 1){
//             vector<int>temp;
//             for(int i = 0; i<nums.size() - 1; i++){
//                 temp.push_back((nums[i] + nums[i+1]) % 10);
//             }
//             nums = move(temp);
//         }
//         return nums[0];
        
//     }
// };
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int ans ;
        for(int i = 0; i<n-1; i++){
            vector<int>a;
            for(int j = 0; j<nums.size() - 1; j++){
                a.push_back((nums[j]+nums[j+1]) % 10);
               
            }
            nums = move(a);
            


        }


        return nums[0];

    



        
    }
};