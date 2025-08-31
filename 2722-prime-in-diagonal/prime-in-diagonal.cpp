class Solution {
public:
bool checkPrime(int ele){
    if(ele <= 1) return false;
    for(int i = 2; i <= (int)sqrt(ele) ; i++){
        if(ele % i == 0) return false;
    }
    return true;
    
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_set<int>st;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j || i + j == n-1){
                    st.insert(nums[i][j]);
                }
            }
        }
        int ans = 0;
        for(int ele : st){
            if(checkPrime(ele) == true){
            ans = max(ans,ele);
            }


        }
        return ans;

        
    }
};