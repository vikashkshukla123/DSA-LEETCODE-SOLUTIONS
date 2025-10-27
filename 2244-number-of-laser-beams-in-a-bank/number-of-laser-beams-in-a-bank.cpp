class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            string b = bank[i];
            int m = b.length();
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if(b[j] - '0' == 1){
                    cnt++;

                }
            }
            
            if(cnt != 0) ans.push_back(cnt);
        }
        int a = 0;
        int k = ans.size();
        for(int i = 0; i<k-1; i++){
            a += ans[i]*ans[i+1];
        }
return a;
        


    }
};