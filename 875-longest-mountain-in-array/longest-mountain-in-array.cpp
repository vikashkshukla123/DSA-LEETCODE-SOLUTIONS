class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            int j = i-1;
            int k = i+1;
            int len = 0;
        
            if(arr[i] > arr[j] && arr[i] > arr[k]){
                len ++;


                while(j >= 0 && arr[j] < arr[j+1]){
                    len++;
                    j--;
                }
                while(k < n && arr[k-1] > arr[k]){
                    len++;
                    k++;
                }

            }
            ans = max(ans,len);
        }
        
        return ans;
    }
};