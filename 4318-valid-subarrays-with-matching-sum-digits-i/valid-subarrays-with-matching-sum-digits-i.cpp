class Solution {
public:
bool isCorrect(long long sum, int x){
    if(sum % 10 != x) return false;
    string s = to_string(sum);
    if(s[0] - '0' == x && s[s.length() - 1] - '0' == x){
        return true;
    }

    return false;
}
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];

                if(isCorrect(sum,x)){
                    ans++;
                }

            }
        }
        return ans;
    }
};