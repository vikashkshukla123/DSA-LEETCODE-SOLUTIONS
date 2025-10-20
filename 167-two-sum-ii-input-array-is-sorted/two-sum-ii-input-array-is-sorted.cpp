class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int>ans;
        int i = 0;
        int j = n-1;
        while(i < j){
            int a = numbers[i];
            int b = numbers[j];

            if(a + b == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(a + b < target){
                i++;
            }else if(a + b > target){
                j--;
            }
        }
        return ans;
    }
};