class Solution {
public:
string binary(int num){
    string s = bitset<32>(num).to_string();
    string trimmed = s.substr(s.find_first_not_of('0'));

    return trimmed;

}
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        string s1 = binary(nums[0]) + binary(nums[1]) + binary(nums[2]);
        ans = max(ans,stoi(s1,nullptr,2));

        string s2 = binary(nums[0]) + binary(nums[2]) + binary(nums[1]);
        ans = max(ans,stoi(s2,nullptr,2));

        string s3 = binary(nums[1]) + binary(nums[0]) + binary(nums[2]);
        ans = max(ans,stoi(s3,nullptr,2));

        string s4 = binary(nums[1]) + binary(nums[2]) + binary(nums[0]);
        ans = max(ans,stoi(s4,nullptr,2));

        string s5 = binary(nums[2]) + binary(nums[0]) + binary(nums[1]);
        ans = max(ans,stoi(s5,nullptr,2));

        string s6 = binary(nums[2]) + binary(nums[1]) + binary(nums[0]);
        ans = max(ans,stoi(s6,nullptr,2));

        return ans;

        
    }
};