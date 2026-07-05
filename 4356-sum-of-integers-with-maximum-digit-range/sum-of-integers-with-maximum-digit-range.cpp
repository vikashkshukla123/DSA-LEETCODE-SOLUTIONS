class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxRange = 0;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            sort(s.begin(),s.end());

            int v1 = s[0] - '0';
            int v2 = s[s.length() - 1] - '0';

            int diff = v2 - v1;
            if(diff > maxRange){
                maxRange = diff;
            }
 

        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            sort(s.begin(),s.end());
            int v1 = s[0] - '0';
            int v2 = s[s.length() - 1] - '0';

            int diff = v2 - v1;
            if(diff == maxRange){
                sum += nums[i];
            }
        }
return sum;
        
    }
};