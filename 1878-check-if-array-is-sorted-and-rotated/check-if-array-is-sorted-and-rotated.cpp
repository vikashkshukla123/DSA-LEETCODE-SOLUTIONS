class Solution {
public:
bool isRotated(vector<int>&B,int x, vector<int>&A){
    int n = B.size();
    bool rotated = true;
    for(int i = 0; i < n; i++){
        if(B[i] != A[(i+x) % n]){
            rotated = false;
            break;
        }

    }
    return rotated;

}
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>A = nums;
        sort(A.begin(),A.end());
        // starting with x = 1 position till its length 
        for(int x = 1; x <= n; x++){
            if(isRotated(nums,x,A)){
                return true;
            }
        }
return false;
    }
};