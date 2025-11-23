class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int>rem1;
        vector<int>rem2;

        int sum = 0;
        for(int &num : nums){
            sum += num;
            if(num % 3 == 1){
                rem1.push_back(num);
            }else if(num % 3 == 2){
                rem2.push_back(num);
            }
        }

        if(sum % 3 == 0){
            return sum;
        }
        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());


        int result = 0;
        int remainder = sum % 3;

        if(remainder == 1){
            int remove1 = rem1.size() >= 1 ? rem1[0] : INT_MAX;
            int remove2 = rem2.size() >= 2 ? (rem2[0] + rem2[1]) : INT_MAX; 

            result = max(result, sum - min(remove1, remove2));
        }

        else{
            int remove1 = rem2.size() >= 1 ? rem2[0] : INT_MAX;
            int remove2 = rem1.size() >= 2 ? (rem1[0] + rem1[1]) : INT_MAX; 

            result = max(result, sum - min(remove1, remove2));


        }
        return result;
        
    }
};