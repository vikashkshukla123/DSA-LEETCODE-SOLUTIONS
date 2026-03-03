class Solution {
public:
    char findKthBit(int n, int k) {
        string one = "0";
        for(int i = 1; i<n; i++){
            string another = one;

            string another1 = "";
            for(int j = 0; j<another.size(); j++){
                if(another[j] == '0'){
                    another1 += '1';
                }else{
                    another1 += '0';
                }
            }

            reverse(another1.begin(),another1.end());

            string one_new = another + "1" + another1;

            one = one_new;
        }
  

  return one[k-1];
        
    }
};