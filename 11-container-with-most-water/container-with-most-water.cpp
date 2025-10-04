class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = -1e9;
        int left = 0;
        int right = n-1;
        while(left<right){
            int length = min(height[right], height[left]);
            int breadth = right - left;
            int area = length*breadth;
            ans = max(ans, area);
            if(height[left]<height[right]){
                left = left + 1;

            }
            else{
                right = right -1;
            }
        }
        return ans;
        
    }
};