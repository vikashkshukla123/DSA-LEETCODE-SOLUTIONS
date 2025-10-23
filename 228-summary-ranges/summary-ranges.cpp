class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {to_string(nums[0])};
        }
        long long range_start = nums[0];
        long long range_end = nums[0];

        for(int i = 1; i<n; i++){
            if(nums[i] == nums[i-1] + 1){
                range_end = nums[i];
            }else{
                string s = "";
                s += to_string(range_start);
                s += "->";
                s += to_string(range_end);

                if(range_start == range_end){
                    ans.push_back(to_string(range_start));
                }else{
                ans.push_back(s);
                }
                

                range_start = nums[i];
                range_end = nums[i];
            }
        }
        if(range_start != range_end){
            string t = "";
            t += to_string(range_start);
            t += "->";
            t += to_string(range_end);

            ans.push_back(t);
        }else{
            ans.push_back(to_string(range_start));
        }
        
        return ans;
    }
};