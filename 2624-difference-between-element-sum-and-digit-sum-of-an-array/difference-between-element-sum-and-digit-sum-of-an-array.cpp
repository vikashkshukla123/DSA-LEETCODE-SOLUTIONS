class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0; i<n; i++){
            s += nums[i];
        }
        int t = 0;
        for(int j = 0; j<n; j++){
            string l = to_string(nums[j]);
            for(int k = 0; k<l.length(); k++){
                t += l[k] - '0';
            }

        }
        return abs(s - t);
    }
}; 