class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         unordered_map<int,int>mp;
         int n = arr.size();

         int maxi = -1e9;
         for(int i = 0; i<arr.size(); i++){
            maxi = max(maxi,arr[i]);
         }


         if(k >= arr.size()){
            return maxi;
         }
         

         int ans = arr[0];
         int current = 0;
         for(int i = 1; i<n; i++){
            if(arr[i] < ans){
                current++;

            }else{
                ans = arr[i];
                current = 1;
            }


            if(current == k){
                break;
            }
         }
return ans;
        
    }
};