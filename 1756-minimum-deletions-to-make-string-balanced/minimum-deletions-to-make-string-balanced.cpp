class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>numberofA(n+1,0);
        vector<int>numberofB(n+1,0);

        int ans = 1e9;
        numberofA[n] = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == 'b'){
                numberofA[i] = numberofA[i+1];
            }else{
                numberofA[i] = 1 + numberofA[i+1];
            }

        }


        numberofB[0] = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
                numberofB[i+1] = numberofB[i];
            }else{
                numberofB[i+1] = 1 + numberofB[i];
            }
        }


        for(int i = 0; i<n; i++){
            int numberofa = numberofA[i+1];
            int numberofb = numberofB[i];


            ans = min(ans, numberofa + numberofb);
        }

return ans;


            
  
    }
};