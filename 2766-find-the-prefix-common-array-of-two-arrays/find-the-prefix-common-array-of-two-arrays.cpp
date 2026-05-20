class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n,0);
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i = 0; i < n; i++){
             mp1[A[i]] = i;
             mp2[B[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int j = 0;
            int cnt = 0;
            for(j = 0; j <= i; j++){
                int ele1 = A[j];
                int ele2_idx = mp2[ele1];

                if(ele2_idx <= i){
                    cnt++;
                }


            }
            ans[i] = cnt;
        }
return ans;
        
    }
};