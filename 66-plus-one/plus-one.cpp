class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;

        int carry = 0;
        for(int i = n-1; i>=0; i--){
            int a = 0;
            if(i == n-1){
                a = digits[i] + carry + 1;
            }else{
                a = digits[i] + carry;
                
            }
            ans.push_back(a % 10);
            carry = a / 10;
            
        }

        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};