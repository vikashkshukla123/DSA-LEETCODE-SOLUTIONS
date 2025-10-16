class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        int inx = 0;
        while(n > 0){
            int a = n % 2;
            if(a == 1 && inx % 2 == 0){
                even++;
            }else if(a == 1 && inx % 2 != 0){
                odd++;
            }
            inx++;
            n = n/2;
            
        }
        
        vector<int>ans;
        ans.push_back(even);
        ans.push_back(odd);

        return ans;

        


        
    }
};