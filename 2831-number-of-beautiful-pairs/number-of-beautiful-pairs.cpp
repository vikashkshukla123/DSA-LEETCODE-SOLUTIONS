class Solution {
public:
int calFirst(int val){
    int digit = 0;
    while(val != 0){
        int num = val % 10;
        digit = num;

        val = val / 10;

    }
    return digit;
}


int calLast(int val){
    int digit = 0;
    while(true){
        digit = val % 10;
        break;
    }

    return digit;
}
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n-1;i++){
            for(int j = i+1; j<n; j++){
                int first_digit = calFirst(nums[i]);
                int last_digit = calLast(nums[j]);
                int val = gcd(first_digit, last_digit);

                if(val == 1) ans++;
            }
        }

        return ans;
        
    }
};