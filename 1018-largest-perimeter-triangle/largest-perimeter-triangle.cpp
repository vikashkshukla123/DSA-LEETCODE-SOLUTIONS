class Solution {
    bool isTriangle(int a, int b, int c){
        if(a + b > c && b + c > a && a + c > b){
            return true;
        }
        return false;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = n-1; i>=2; i--){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            int area;

            if(isTriangle(a,b,c)){
                area = a + b + c;
                ans = max(ans,area);
                break;
            }
        }

        return ans;

       

       
    }
};