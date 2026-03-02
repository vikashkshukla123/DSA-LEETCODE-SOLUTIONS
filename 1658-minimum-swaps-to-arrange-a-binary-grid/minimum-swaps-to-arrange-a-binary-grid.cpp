class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>zeroAtEnd(n,0);
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = n-1; j>=0; j--){
                if(grid[i][j] == 1){
                    zeroAtEnd[i] = 0;
                    break;
                }
                else{
                    int idx = j;
                    while(j >= 0 && grid[i][j] == 0){
                        cnt++;
                        j--;
                    }
                    zeroAtEnd[i] = cnt;
                    break;
                }



            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            int zero_required = n - i - 1;

            if(zeroAtEnd[i] >= zero_required) continue;

            int j = i + 1;

            while(j < n && zeroAtEnd[j] < zero_required){
                j++;
            }

            if(j == n){
                return -1;
            }


            while(j > i){
                swap(zeroAtEnd[j], zeroAtEnd[j-1]);
                ans++;
                j--;
            }

            
        }

        return ans;
        
        
    }
};